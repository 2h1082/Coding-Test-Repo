#include "bits/stdc++.h"
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    
    int N;
    cin>>N;
    vector<int> A(N+1,0), Dp(N+1,0);
    for(int i=1;i<=N;++i) cin>>A[i];
    
    Dp[1]=A[1];
    Dp[2]=A[1]+A[2];
    for(int i=3;i<=N;++i)
    {
        Dp[i]=max({Dp[i-1], Dp[i-2]+A[i], Dp[i-3]+A[i-1]+A[i]});
    }
    cout<<Dp[N];
}