#include "bits/stdc++.h"
using namespace std;

int Mod=10007;
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    
    int N;
    cin>>N;
    
    vector<vector<int>> Dp(N+1,vector<int>(10,0));
    for(int i=0;i<10;++i) Dp[1][i]=1;
    for(int l=2;l<=N;++l)
    {
        for(int i=0;i<10;++i)
        {
            for(int j=0;j<=i;++j) Dp[l][i]=(Dp[l][i]+Dp[l-1][j])%Mod;
        }
    }
    int Ans=accumulate(Dp[N].begin(),Dp[N].end(),0);
    Ans%=Mod;
    cout<<Ans;
}