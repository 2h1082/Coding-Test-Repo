#include "bits/stdc++.h"
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    
    int N;
    cin>>N;
    
    vector<int> A(N), Dp(N);
    for(auto& a : A) cin>>a;
    
    int Ans=0;
    for(int i=0;i<N;++i)
    {
        Dp[i]=A[i];
        for(int j=0;j<i;++j)
        {
            if(A[i] > A[j]) Dp[i]=max(Dp[i],Dp[j]+A[i]);
        }
        Ans=max(Ans,Dp[i]);
    }
    cout<<Ans;
}