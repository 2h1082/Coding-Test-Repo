#include "bits/stdc++.h"
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    
    int N;
    cin>>N;
    vector<int> A(N+1), Dp(N+1,0);
    for(int i=1;i<=N;++i) 
    {
        cin>>A[i];
        Dp[i]=A[i];
    }
    for(int i=2;i<=N;++i) 
    {
        for(int j=1;j<i;++j)
        {
            Dp[i]=max(Dp[i],Dp[i-j]+A[j]);
        }
    }
    cout<<Dp[N];
}