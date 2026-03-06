#include "bits/stdc++.h"
using namespace std;

int Mod=1000000009;
long long Dp[1000001];
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    
    int T;
    cin>>T;
    Dp[1]=1;
    Dp[2]=2;
    Dp[3]=4;
    for(int i=4;i<=1000000;++i) Dp[i]=(Dp[i-3]+Dp[i-2]+Dp[i-1])%Mod;
    while(T--)
    {
        int N;
        cin>>N;
        cout<<Dp[N]<<'\n';
    }
}