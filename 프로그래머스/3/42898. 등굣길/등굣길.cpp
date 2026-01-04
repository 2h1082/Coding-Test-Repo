#include "bits/stdc++.h"
using namespace std;

int Mod=1000000007;
int solution(int M, int N, vector<vector<int>> P) 
{
    vector<vector<int>> Dp(N,vector<int>(M,0));
    
    // 초기 맵 상태 설정
    Dp[0][0]=1;
    for(auto& Cur : P) Dp[Cur[1]-1][Cur[0]-1]=-1;
    
    for(int i=1;i<N;++i)
    {
        if(Dp[i][0]==-1) continue;
        Dp[i][0]=Dp[i-1][0];
    }
    for(int i=1;i<M;++i)
    {
        if(Dp[0][i]==-1) continue;
        Dp[0][i]=Dp[0][i-1];
    }
    
    // Dp 갱신
    for(int i=1;i<N;++i)
    {
        for(int j=1;j<M;++j)
        {
            if(Dp[i][j]==-1) continue;
            
            if(Dp[i-1][j]>0) Dp[i][j]+=Dp[i-1][j];
            if(Dp[i][j-1]>0) Dp[i][j]+=Dp[i][j-1];
            Dp[i][j]%=Mod;
        }
    }
    return Dp[N-1][M-1];
}