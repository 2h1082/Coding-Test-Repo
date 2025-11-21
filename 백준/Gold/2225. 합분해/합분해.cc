#include "bits/stdc++.h"
using namespace std;

int Mod=1000000000;
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    int N,K;
    cin>>N>>K;
    
    vector<vector<int>> Dp(K+1,vector<int>(N+1,0));
    for(int i=0;i<=N;++i) Dp[1][i]=1;
    
    for(int i=2;i<=K;++i)
    {
        for(int j=0;j<=N;++j)
        {
            if(j==0) Dp[i][j]=1;
            else     Dp[i][j]=(Dp[i-1][j]+Dp[i][j-1])%Mod;
        }
    }
    cout<<Dp[K][N];
}