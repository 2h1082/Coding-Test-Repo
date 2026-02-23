#include "bits/stdc++.h"
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    
    int N,M;
    cin>>N>>M;
    
    vector<int> Dp(N);
    for(int i=0;i<N;++i)
    {
        cin>>Dp[i];
        if(i>0) Dp[i]+=Dp[i-1];
    }
    
    while(M--)
    {
        int S,E;
        cin>>S>>E;
        
        int Ans=Dp[E-1];
        if(S>1) Ans-=Dp[S-2];
        cout<<Ans<<'\n';
    }
}