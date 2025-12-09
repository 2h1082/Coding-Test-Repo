#include "bits/stdc++.h"
using namespace std;
#define w first
#define v second
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    int N,M;
    cin>>N>>M;
    
    vector<vector<pair<int,int>>> G(N+1);
    while(M--)
    {
        int A,B,C;
        cin>>A>>B>>C;
        
        G[A].push_back({C,B});
        G[B].push_back({C,A});
    }
    
    vector<int> Dist(N+1,1e9);
    Dist[1]=0;
    priority_queue<pair<int,int>,vector<pair<int,int>>,greater<>> pq;
    pq.push({0,1});
    while(!pq.empty())
    {
        int Cur=pq.top().v, Weight=pq.top().w;
        pq.pop();
        if(Dist[Cur]<Weight) continue;
        
        for(auto& [Cost, Nxt]:G[Cur])
        {
            int NxtCost=Cost+Weight;
            if(NxtCost<Dist[Nxt])
            {
                pq.push({NxtCost,Nxt});
                Dist[Nxt]=NxtCost;
            }
        }
    }
    cout<<Dist[N];
}