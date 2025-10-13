#include <bits/stdc++.h>

using namespace std;

typedef pair<int,int> Edge;
int main()
{
    int N=0,M=0;
    cin>>N>>M;
    
    vector<vector<Edge>> Graph(N+1);
    while(M--)
    {
        int F,T,C;
        cin>>F>>T>>C;
        Graph[F].push_back({C,T});
        Graph[T].push_back({C,F});
    }
    priority_queue<Edge,vector<Edge>,greater<>> pq;
    pq.push({0,1});
    vector<bool> Visited(N+1,false);
    int EdgeCnt=0,Total=0, Max=0;
    
    while(!pq.empty()&&EdgeCnt<N)
    {
        auto [W,Cur]=pq.top();
        pq.pop();
        if(Visited[Cur]) continue;
        Max=max(W,Max);
        Total+=W;
        EdgeCnt++;
        Visited[Cur]=true;
        for(auto NextEdge : Graph[Cur])
        {
            if(!Visited[NextEdge.second])
            {
                pq.push(NextEdge);
            }
        }
    }
    cout<<Total-Max;
}