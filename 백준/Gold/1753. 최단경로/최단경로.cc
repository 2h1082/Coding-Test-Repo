#include <iostream>
#include <vector>
#include <queue>
#include <climits>

using namespace std;

int V, E;
vector<vector<pair<int,int>>> Graph;
int main()
{
    int Start=0;
    cin>>V>>E>>Start;
    Graph.assign(V+1,vector<pair<int,int>>());
    while(E--)
    {
        int From,To,Weight;
        cin>>From>>To>>Weight;
        Graph[From].push_back({Weight,To});
    }
    priority_queue<pair<long long,int>> pq;
    vector<long long> Dist(V+1,LLONG_MAX);
    pq.push({0,Start});
    Dist[Start]=0;
    while(!pq.empty())
    {
        long long CurDist=-pq.top().first;
        int CurNode=pq.top().second;
        pq.pop();
        if(CurDist>Dist[CurNode]) continue;
        for(auto NextInfo:Graph[CurNode])
        {
            long long NextDist=CurDist+NextInfo.first;
            int NextNode=NextInfo.second;
            if(NextDist<Dist[NextNode])
            {
                pq.push({-NextDist,NextNode});
                Dist[NextNode]=NextDist;
            }
        }
    }
    for(int i=1;i<=V;++i)
    {
        if(Dist[i]>=LLONG_MAX) cout<<"INF\n";
        else                   cout<<Dist[i]<<"\n";
    }
}