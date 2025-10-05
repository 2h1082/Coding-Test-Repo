#include <bits/stdc++.h>

using namespace std;

int main()
{
    int N,S;
    cin>>N>>S;
    vector<int> Nums(N,0);
    for(auto& Num : Nums)
    {
        cin>>Num;
    }
    int L=0, R=0, Min=INT_MAX;
    int Sum=0;
    while(R<N)
    {
        Sum+=Nums[R];
        while(Sum>=S)
        {
            Min=min(Min,R-L+1);
            Sum-=Nums[L];
            L++;
        }
        R++;
    }
    if(Min==INT_MAX) cout<<0;
    else             cout<<Min;
}