#include "bits/stdc++.h"
using namespace std;
int N,P,K;
vector<vector<pair<int,int>>> Edge;

bool Dijkstra(int Limit)
{
    vector<int> Dist(N+1,1e9);
    priority_queue<pair<int,int>,vector<pair<int,int>>,greater<>> pq;
    
    Dist[1]=0;
    pq.push({0,1});
    while(!pq.empty())
    {
        auto [FreeCnt,Cur]=pq.top();
        pq.pop();
        
        if(Dist[Cur]<FreeCnt) continue;
        if(Cur==N) break;
        
        for(auto& Info : Edge[Cur])
        {
            int Nxt=Info.second, NxtCost=Info.first;
            int NxtFreeCnt=FreeCnt+(NxtCost>Limit);
            if(NxtFreeCnt<Dist[Nxt] && NxtFreeCnt<=K)
            {
                Dist[Nxt]=NxtFreeCnt;
                pq.push({NxtFreeCnt,Nxt});
            }
        }
    }
    return Dist[N]<=K;
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    
    cin>>N>>P>>K;
    Edge.reserve(N+1);
    int Max=0;
    while(P--)
    {
        int F,T,W;
        cin>>F>>T>>W;
        Edge[F].push_back({W,T});
        Edge[T].push_back({W,F});
        Max=max(Max,W);
    }
    
    int L=0, R=Max;
    int Ans=-1;
    while(L<=R)
    {
        int Mid=(L+R)/2;
        if(Dijkstra(Mid))
        {
            Ans=Mid;
            R=Mid-1;
        }
        else
        {
            L=Mid+1;
        }
    }
    cout<<Ans;
}