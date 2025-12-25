#include "bits/stdc++.h"

using namespace std;

int Mod=1000000007;
int solution(int M, int N, vector<vector<int>> P) {
    int Ans = 0;
    vector<vector<bool>> Wet(N,vector<bool>(M,false));
    vector<vector<int>> Dp(N,vector<int>(M,0));
    
    for(auto& R: P)
    {
        int x=R[0]-1 ,y=R[1]-1;
        Wet[y][x]=true;
    }
    
    Dp[0][0]=0;
    for(int i=1;i<N;++i)
    {
        if(Wet[i][0]) break;;
        Dp[i][0]=1;
    }
    for(int j=1;j<M;++j) 
    {
        if(Wet[0][j]) break;;
        Dp[0][j]=1;
    }
    
    
    for(int i=1;i<N;++i)
    {
        for(int j=1;j<M;++j)
        {
            if(Wet[i][j]) continue;
            if(!Wet[i-1][j]) Dp[i][j]+=Dp[i-1][j];
            if(!Wet[i][j-1]) Dp[i][j]+=Dp[i][j-1];
            Dp[i][j]%=Mod;
        }
    }
    Ans=Dp[N-1][M-1];
    return Ans;
}