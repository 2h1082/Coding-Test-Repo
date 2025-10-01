#include <iostream>
#include <vector>
#include <queue>
#include <climits>

using namespace std;
int N=0,M=0,X=0;
vector<vector<pair<int,int>>> Graph;
vector<vector<int>> DP;
int Max=0;
void Dijkstra(int Start)
{
    
    priority_queue<pair<int,int>> pq;
    pq.push({0,Start});
    DP[Start][Start]=0;
    while(!pq.empty())
    {
        int Cur=pq.top().second;
        int CurCost=-pq.top().first;
        pq.pop();
        if(CurCost>DP[Start][Cur]) continue;
        
        for(auto NextInfo:Graph[Cur])
        {
            int Next=NextInfo.second;
            int NextCost=CurCost+NextInfo.first;
            if(DP[Start][Next]>NextCost)
            {
                DP[Start][Next]=NextCost;
                pq.push({-NextCost,Next});
            }
        }
    }
}
int main()
{
    cin>>N>>M>>X;
    Graph.assign(N+1,vector<pair<int,int>>());
    DP.assign(N+1,vector<int>(N+1,INT_MAX));
    while(M--)
    {
        int From=0,To=0,Time=0;
        cin>>From>>To>>Time;
        Graph[From].push_back({Time,To});
    }
    
    for(int i=1;i<=N;++i)
    {
        Dijkstra(i);
    }
    for (int i=1;i<=N;++i)
    {
        if (i==X) continue;
        Max=max(Max,DP[i][X]+DP[X][i]);
    }
    cout<<Max;
}