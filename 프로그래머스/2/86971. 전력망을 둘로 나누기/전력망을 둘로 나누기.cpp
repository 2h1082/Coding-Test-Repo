#include <bits/stdc++.h>
using namespace std;

vector<vector<int>> Graph;
vector<int> ChildCnt;
int Min=1e9;
int DFS(int Cur, int Par, const int& N)
{
    for(int& Nxt : Graph[Cur])
    {
        if(Nxt==Par) continue;
        
        int NxtChildCnt=DFS(Nxt,Cur,N);
        Min=min(Min,abs(N-2*NxtChildCnt));
        ChildCnt[Cur]+=NxtChildCnt;
    }
    return ChildCnt[Cur];
}
int solution(int N, vector<vector<int>> Wires) {
    Graph.resize(N+1);
    for(auto& Edge : Wires)
    {
        Graph[Edge[0]].push_back(Edge[1]);
        Graph[Edge[1]].push_back(Edge[0]);
    }
    ChildCnt.assign(N+1,1);
    DFS(1,0,N);
    return Min;
}
