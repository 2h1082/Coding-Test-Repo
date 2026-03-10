#include "bits/stdc++.h"
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    
    int N;
    cin>>N;
    
    vector<int> Dp(N+1,0);
    Dp[1]=1;
    Dp[2]=2;
    for(int i=3;i<=N;++i) Dp[i]=(Dp[i-2]+Dp[i-1])%15746;
    cout<<Dp[N];
}