#include <bits/stdc++.h>

using namespace std;
typedef pair<int,int> Edge;

int main()
{
    int V,E;
    cin>>V>>E;
    vector<vector<Edge>> Graph(V+1,vector<Edge>());
    while(E--)
    {
        int From,To,Weight;
        cin>>From>>To>>Weight;
        Graph[From].push_back({Weight,To});
        Graph[To].push_back({Weight,From});
    }
    priority_queue<Edge,vector<Edge>,greater<>> pq;
    vector<bool> Visited(V+1,false);
    pq.push({0,1});
    int Total=0, EdgeCount=0;
    while(!pq.empty()&&EdgeCount<V)
    {
        int CurCost=pq.top().first;
        int Cur=pq.top().second;
        pq.pop();
        if(Visited[Cur]) continue;
        Visited[Cur]=true;
        Total+=CurCost;
        EdgeCount++;
        for(const auto& NextEdge : Graph[Cur])
        {
            int Next=NextEdge.second;
            int NextWeight=NextEdge.first;
            if(!Visited[Next])
            {
                pq.push({NextWeight,Next});
            }
        }
    }
    cout<<Total;
}