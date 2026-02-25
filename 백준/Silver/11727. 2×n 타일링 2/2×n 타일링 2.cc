#include "bits/stdc++.h"
using namespace std;

int Mod=10007;
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    
    int N;
    cin>>N;
    vector<int> Dp(N,0);
    Dp[0]=1;
    Dp[1]=3;
    for(int i=2;i<N;++i) Dp[i]=(Dp[i-2]*2+Dp[i-1])%Mod;
    cout<<Dp[N-1];
}