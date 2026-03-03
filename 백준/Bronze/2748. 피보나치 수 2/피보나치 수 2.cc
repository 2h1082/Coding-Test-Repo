#include "bits/stdc++.h"
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    
    int N;
    cin>>N;
    
    vector<long long> Dp(N+1,0);
    Dp[1]=Dp[2]=1;
    for(int i=3;i<=N;++i) Dp[i]=Dp[i-1]+Dp[i-2];
    cout<<Dp[N];
}