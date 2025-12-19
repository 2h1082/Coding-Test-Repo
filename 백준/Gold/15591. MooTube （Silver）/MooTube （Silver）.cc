#include "bits/stdc++.h"
using namespace std;
vector<vector<pair<int,int>>> Adj;
int N, Q;
void DFS(int Cur, int Prev, int Min, int K, int& Ans)
{
    for(auto [U,Nxt] : Adj[Cur])
    {
        if(Prev==Nxt) continue;
        int NxtU=min(Min,U);
        
        if(NxtU < K) continue;
        Ans++;
        DFS(Nxt,Cur,NxtU,K,Ans);
    }
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    cin>>N>>Q;
    
    Adj.resize(N+1);
    for(int i=1;i<N;++i)
    {
        int p,q,r;
        cin>>p>>q>>r;
        
        Adj[p].push_back({r,q});
        Adj[q].push_back({r,p});
    }
    while(Q--)
    {
        int k, v;
        cin>>k>>v;
        
        int Ans=0;
        DFS(v,0,1e9,k,Ans);
        cout<<Ans<<'\n';
    }
}