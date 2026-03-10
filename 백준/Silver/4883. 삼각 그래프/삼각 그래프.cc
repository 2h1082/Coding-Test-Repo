#include "bits/stdc++.h"
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    
    int K=1;
    while(1)
    {
        int N;
        cin>>N;
        if(N==0) break;
        
        vector<vector<int>> A(N,vector<int>(3,0)), Dp(N,vector<int>(3,1e9));
        for(auto& r: A)
        {
            for(auto& c : r) cin>>c;
        }
        Dp[0][1]=A[0][1];
        Dp[0][2]=Dp[0][1]+A[0][2];
        for(int i=1;i<N;++i)
        {
            Dp[i][0]=min(Dp[i-1][1],Dp[i-1][0])+A[i][0];
            Dp[i][1]=min({Dp[i][0],Dp[i-1][0],Dp[i-1][1],Dp[i-1][2]})+A[i][1];
            Dp[i][2]=min({Dp[i][1],Dp[i-1][1],Dp[i-1][2]})+A[i][2];
        }
        cout<<K<<". "<<Dp[N-1][1]<<'\n';
        ++K;
    }
}