#include "bits/stdc++.h"
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    
    int N;
    cin>>N;
    
    vector<int> A(N,0);
    for(auto& a : A) cin>>a;
    vector<int> Dp=A;
    Dp[1]+=A[0];
    Dp[2]+=max(A[0],A[1]);
    
    for(int i=3;i<N;++i)
    {
        Dp[i]+=max(A[i-1]+Dp[i-3],Dp[i-2]);
    }
    cout<<Dp[N-1];
}