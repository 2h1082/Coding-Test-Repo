#include "bits/stdc++.h"
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    
    vector<long long> Dp(101,0);
    Dp[1]=Dp[2]=Dp[3]=1;
    Dp[4]=Dp[5]=2;
    for(int i=6;i<=100;++i) Dp[i]=Dp[i-1]+Dp[i-5];
    
    int T;
    cin>>T;
    while(T--)
    {
        int N;
        cin>>N;
        cout<<Dp[N]<<'\n';
    }
}