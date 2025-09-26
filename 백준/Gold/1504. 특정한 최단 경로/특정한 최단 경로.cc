#include <iostream>
#include <vector>
#include <queue>
#include <climits>


using namespace std;

int N=0,E=0;
vector<vector<pair<int,int>>> Adj;
vector<long long> Dijkstra(int Start)
{
    vector<long long> Result(N+1,LLONG_MAX);
    priority_queue<pair<long long,int>,vector<pair<long long,int>>,greater<>> pq;
    pq.push({0,Start});
    Result[Start]=0;
    while(!pq.empty())
    {
        long long CurDist=pq.top().first;
        int Cur=pq.top().second;
        pq.pop();
        if(CurDist>Result[Cur]) continue;
        for(auto NextInfo:Adj[Cur])
        {
            int Next=NextInfo.first;
            long long NextDist=NextInfo.second;
            if(Result[Next]>NextDist+CurDist)
            {
                Result[Next]=NextDist+CurDist;
                pq.push({Result[Next],Next});
            }
        }
    }
    return Result;
}
int main()
{
    cin>>N>>E;
    Adj.assign(N+1,vector<pair<int,int>>());
    while(E--)
    {
        int From=0,To=0,Weight=0;;
        cin>>From>>To>>Weight;
        Adj[From].push_back({To,Weight});
        Adj[To].push_back({From,Weight});
    }
    int V1=0,V2=0;
    cin>>V1>>V2;
    vector<long long> StartS=Dijkstra(1);
    vector<long long> StartV1=Dijkstra(V1);
    vector<long long> StartV2=Dijkstra(V2);
    long long Dist1=LLONG_MAX,Dist2=LLONG_MAX;
    
    if(StartS[V1]!=LLONG_MAX&&StartV1[V2]!=LLONG_MAX&&StartV2[N]!=LLONG_MAX)
    {
        Dist1=StartS[V1]+StartV1[V2]+StartV2[N];
    }
    if(StartS[V2]!=LLONG_MAX&&StartV2[V1]!=LLONG_MAX&&StartV1[N]!=LLONG_MAX)
    {
        Dist2=StartS[V2]+StartV2[V1]+StartV1[N];
    }
    if(Dist1==LLONG_MAX&&Dist2==LLONG_MAX) cout<<"-1";
    else                                   cout<<min(Dist1,Dist2);
}
