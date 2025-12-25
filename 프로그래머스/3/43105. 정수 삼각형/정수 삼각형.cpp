#include "bits/stdc++.h"

using namespace std;

int solution(vector<vector<int>> Tri) {
    int Ans = 0;
    int N= Tri.size();
    vector<vector<int>> Dp(N, vector<int>(N,0));
    Dp[0][0]=Tri[0][0];
    for(int i=1;i<N;++i)
    {
        auto& Cur=Tri[i];
        int M=Cur.size();
        for(int j=0;j<M;++j)
        {
            if(j>0)     Dp[i][j]=max(Dp[i][j],Dp[i-1][j-1]+Cur[j]);
            if(j<M-1)   Dp[i][j]=max(Dp[i][j],Dp[i-1][j]+Cur[j]);
        }
    }
    Ans=*max_element(Dp[N-1].begin(),Dp[N-1].end());
    return Ans;
}