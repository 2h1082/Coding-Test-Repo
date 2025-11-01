#include <bits/stdc++.h>
using namespace std;
using ll=long long;
using Edge=pair<int,int>;

int N,M;
vector<vector<int>> Dijikstra(int S, int D, vector<vector<Edge>>& Graph, vector<ll>& Dist, vector<vector<bool>>& Removed)
{
    priority_queue<Edge,vector<Edge>,greater<>> q;
    q.push({0,S});
    vector<vector<int>> Prev(N);
    while(!q.empty())
    {
        auto [Cost, Cur]=q.top(); 
        q.pop();
        if(Dist[Cur]<Cost) continue;
        for(auto [W,Next]:Graph[Cur])
        {
            if(Removed[Cur][Next]) continue;
            ll NextCost=1LL*Cost+W;
            if(Dist[Next]>NextCost)
            {
                q.push({NextCost,Next});
                Dist[Next]=NextCost;
                Prev[Next].clear();
                Prev[Next].push_back(Cur);
            }
            else if(Dist[Next]==NextCost)
            {
                Prev[Next].push_back(Cur);
            }
        }
    }
    return Prev;
}

void RemoveEdges(int Cur, vector<vector<bool>>& Removed, vector<vector<int>>& Prev)
{
    for(int Nxt : Prev[Cur])
    {
        if(!Removed[Nxt][Cur])
        {
            Removed[Nxt][Cur]=true;
            RemoveEdges(Nxt,Removed,Prev);
        }
    }
}
int main()
{
    while(1)
    {
        cin>>N>>M;
        if(N==0&&M==0) break;
        
        vector<vector<Edge>> Graph(N);
        vector<vector<bool>> Removed(N,vector<bool>(N,false));
        vector<ll> Dist(N,1e9);
        int S, D;
        cin>>S>>D;
        while(M--)
        {
            int U,V,P;
            cin>>U>>V>>P;
            Graph[U].push_back({P,V});
        }
        // 최단 경로 찾기 & 이용된 간선 반환
        Dist[S]=0;
        vector<vector<int>> Prev=Dijikstra(S,D,Graph,Dist,Removed);
        RemoveEdges(D,Removed,Prev);
        Dist.assign(N,1e9);
        Dist[S]=0;
        Dijikstra(S,D,Graph,Dist,Removed);
        ll Res=Dist[D]==1e9 ? -1 : Dist[D];
        cout<<Res<<"\n";
    }  
}