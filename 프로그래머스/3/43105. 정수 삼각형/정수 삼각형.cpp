#include "bits/stdc++.h"
using namespace std;

int solution(vector<vector<int>> Tri) {
    int N=Tri.size();
    
    // Dp 테이블 초기화
    vector<vector<int>> Dp=Tri;
    for(auto& R : Dp)
    {
        for(auto& C : R)
        {
            C=0;
        }
    }
    Dp[0][0]=Tri[0][0];
    
    // Dp 갱신
    for(int i=1;i<N;++i)
    {
        int M=Dp[i].size();
        for(int j=0;j<M;++j)
        {
            if(j>0)   Dp[i][j]=max(Dp[i][j],Dp[i-1][j-1]+Tri[i][j]);
            if(j<M-1) Dp[i][j]=max(Dp[i][j],Dp[i-1][j]+Tri[i][j]);
        }
    }
    
    return *max_element(Dp[N-1].begin(),Dp[N-1].end());
}