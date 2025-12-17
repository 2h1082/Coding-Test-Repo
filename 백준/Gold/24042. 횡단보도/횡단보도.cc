#include "bits/stdc++.h"
using namespace std;
using ll=long long;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    int N,M;
    cin>>N>>M;
    
    vector<vector<pair<int,int>>> A(N);
    for(int i=0;i<M;++i)
    {
        int F,T;
        cin>>F>>T;
        --F; --T;
        A[F].push_back({T,i});
        A[T].push_back({F,i});
    }
    
    vector<ll> Dist(N,4e18);
    priority_queue<pair<ll,int>, vector<pair<ll,int>>, greater<>> pq;
    Dist[0]=0;
    pq.push({0,0});
    
    while(!pq.empty())
    {
        auto [CurTime, Cur] = pq.top();
        pq.pop();
        if(Dist[Cur]<CurTime) continue;
        
        for(auto [Nxt,Time] : A[Cur])
        {
            ll NxtTime;
            if(CurTime <= Time) NxtTime=Time;
            else                NxtTime=Time+((CurTime-Time+M-1)/M)*M;
            
            if(Dist[Nxt] > NxtTime+1)
            {
                Dist[Nxt]=NxtTime+1;
                pq.push({Dist[Nxt],Nxt});
            }
        }
    }
    cout<<Dist[N-1];
}