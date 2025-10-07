#include <bits/stdc++.h>

using namespace std;

int main()
{
    int N=0;
    cin>>N;
    vector<int> Nums(N,0);
    for(auto& Num : Nums)
    {
        cin>>Num;
    }
    vector<int> DP;
    for(auto& Num : Nums)
    {
        if(DP.empty()||DP.back()<Num)
        {
            DP.push_back(Num);
        }
        else
        {
            auto it=lower_bound(DP.begin(),DP.end(),Num);
            *it=Num;
        }
    }
    cout<<DP.size();
}