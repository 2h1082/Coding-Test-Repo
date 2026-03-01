#include "bits/stdc++.h"
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    
    int N;
    cin>>N;
    
    vector<pair<int,int>> A(N);
    for(auto& [t,p]:A) cin>>t>>p;
    vector<int> Dp(N+1,0);
    for(int i=0;i<N;++i)
    {
        Dp[i+1]=max(Dp[i],Dp[i+1]);
        int E=i+A[i].first;
        if(E <= N) Dp[E]=max(Dp[E],Dp[i]+A[i].second);
    }
    cout<<Dp[N];
}