#include "bits/stdc++.h"
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    int N,D;
    cin>>N>>D;
    
    vector<vector<pair<int,int>>> G(10001);
    while(N--)
    {
        int S, E, W;
        cin>>S>>E>>W;
        G[S].push_back({W,E});
    }
    // 지름길이 아닌 그냥 도로 간선 추가
    for(int i=0;i<D;++i)
    {
        G[i].push_back({1,i+1});
    }
        
    priority_queue<pair<int,int>, vector<pair<int,int>>, greater<>> pq;
    pq.push({0,0});
    vector<int> Dist(10001,1e9);
    Dist[0]=0;
    while(!pq.empty())
    {
        int Cur=pq.top().second, W=pq.top().first;
        pq.pop();
        if(Cur==D || W > Dist[Cur]) continue;
        for(auto& [NxtW, Nxt] : G[Cur])
        {
            int NxtCost=NxtW+Dist[Cur];
            if(NxtCost < Dist[Nxt])
            {
                pq.push({NxtCost,Nxt});
                Dist[Nxt]=NxtCost;
            }
        }
    }
    cout<<Dist[D];
}
