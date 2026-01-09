#include <bits/stdc++.h>
using namespace std;

int solution(int N, vector<vector<int>> Edge) 
{
    int Ans=0;
    vector<vector<int>> Graph(N);
    for(auto& Cur : Edge)
    {
        Graph[Cur[0]-1].push_back(Cur[1]-1);
        Graph[Cur[1]-1].push_back(Cur[0]-1);
    }
    
    // BFS
    int Max=0;
    vector<int> Dist(N,-1);
    queue<int> Q;
    Q.push(0);
    Dist[0]=0;
    while(!Q.empty())
    {
        auto Cur=Q.front();
        Q.pop();
        for(auto Nxt : Graph[Cur])
        {
            if(Dist[Nxt]!=-1) continue;
            
            Dist[Nxt]=Dist[Cur]+1;
            Max=max(Max,Dist[Nxt]);
            Q.push(Nxt);
        }
    }
    Ans=count(Dist.begin(),Dist.end(),Max);
    return Ans;
}