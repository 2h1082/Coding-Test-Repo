#include "bits/stdc++.h"
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    
    int T;
    cin>>T;
    vector<int> Dp(12,1e9);
    Dp[1]=1;
    Dp[2]=2;
    Dp[3]=4;
    for(int i=4;i<=11;++i)
    {
        Dp[i]=Dp[i-1]+Dp[i-2]+Dp[i-3];
    }
    while(T--)
    {
        int N;
        cin>>N;
        cout<<Dp[N]<<'\n';
    }
}