#include <bits/stdc++.h>

using namespace std;
using Edge=pair<int,int>;

vector<vector<Edge>> Graph, RevGraph;
vector<int> Rank;
int main()
{
    int N=0, M=0;
    cin>>N>>M;
    Graph.assign(N+1,vector<Edge>());
    RevGraph.assign(N+1,vector<Edge>());
    Rank.assign(N+1,0);
    while(M--)
    {
        int F, T, W;
        cin>>F>>T>>W;
        Graph[F].push_back({W,T});
        RevGraph[T].push_back({W,F});
        Rank[T]++;
    }
    int S, E;
    cin>>S>>E;
    queue<int> q;
    vector<int> Dist(N+1,0);
    q.push(S);
    while(!q.empty())
    {
        int Cur=q.front();
        q.pop();
        for(auto& [Cost,Nxt] : Graph[Cur])
        {
            int NxtCost=Dist[Cur]+Cost;
            if(Dist[Nxt]<NxtCost)
            {
                Dist[Nxt]=NxtCost;
            }
            Rank[Nxt]--;
            if(!Rank[Nxt])
            {
                q.push(Nxt);
            }
        }
    }
    int Cnt=0;
    vector<bool> Visited(N+1,false);
    q.push(E);
    Visited[E]=true;
    while(!q.empty())
    {
        int Cur=q.front();
        q.pop();
        for(auto& [Cost,Prev] : RevGraph[Cur])
        {
            if(Dist[Prev]+Cost==Dist[Cur])
            {
                Cnt++;
                if(!Visited[Prev])
                {
                    Visited[Prev]=true;
                    q.push(Prev);
                }
            }
        }
    }
    cout<<Dist[E]<<"\n"<<Cnt;
}