#include "bits/stdc++.h"
using namespace std;

int solution(int N, vector<vector<int>> Results) 
{
    int Ans = 0;
    vector<vector<int>> Adj(N,vector<int>(N,0));
    
    // 초기 그래프 구성
    for(auto& Cur : Results)  Adj[Cur[0]-1][Cur[1]-1]=1;
    
    // 플로이드 워셜
    for(int k=0;k<N;++k)
    {
        for(int i=0;i<N;++i)
        {
            for(int j=0;j<N;++j)
            {
                if(!Adj[i][k] || !Adj[k][j]) continue;
                Adj[i][j]=1;
            }
        }
    }
    
    // 순위 확정 가능 여부 확인
    for(int i=0;i<N;++i)
    {
        int Cnt=0;
        for(int j=0;j<N;++j)
        {
            if(Adj[i][j] || Adj[j][i]) ++Cnt;
        }
        if(Cnt==N-1) ++Ans;
    }
    
    return Ans;
}