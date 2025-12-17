#include "bits/stdc++.h"
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    int N,M;
    cin>>N>>M;
    
    vector<vector<int>> Map(N,vector<int>(M,0)), Dp(N,vector<int>(M,-1e9));
    for(auto& r : Map)
    {
        for(auto& c : r)
        {
            cin>>c;
        }
    }
    
    Dp[0][0]=Map[0][0];
    for(int j=1;j<M;++j) Dp[0][j]=Dp[0][j-1]+Map[0][j];
    
    for(int i=1;i<N;++i)
    {
        vector<int> L(M,-1e9), R(M,-1e9);
        
        L[0]=Dp[i-1][0]+Map[i][0];
        for(int j=1;j<M;++j) L[j]=max(L[j-1],Dp[i-1][j])+Map[i][j];
        
        R[M-1]=Dp[i-1][M-1]+Map[i][M-1];
        for(int j=M-2;j>=0;--j) R[j]=max(R[j+1],Dp[i-1][j])+Map[i][j];
        
        for(int j=0;j<M;++j) Dp[i][j]=max(L[j],R[j]);
    }
    cout<<Dp[N-1][M-1];
}