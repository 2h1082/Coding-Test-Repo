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
    sort(Nums.begin(),Nums.end());
    for(auto& Num : Nums)
    {
        cout<<Num<<"\n";
    }
}