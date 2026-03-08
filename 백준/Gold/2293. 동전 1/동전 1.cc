#include "bits/stdc++.h"
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    
    int N,K;
    cin>>N>>K;
    vector<int> A(N), Dp(K+1,0);
    for(auto& a : A) cin>>a;
    Dp[0]=1;
    
    for(auto& a : A)
    {
        for(int i=a;i<=K;++i)
        {
            Dp[i]+=Dp[i-a];
        }
    }
    cout<<Dp[K];
}