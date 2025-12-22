#include "bits/stdc++.h"
using namespace std;
 
int N,M,K;
vector<int> Market;
vector<vector<int>> Dp, Dist;
vector<vector<pair<int,int>>> Adj;
void Dijkstra(int StartIdx, int StartNode)
{
    for(int i=1;i<=N;++i) Dist[StartIdx][i]=1e9;
    priority_queue<pair<int,int>,vector<pair<int,int>>,greater<>> pq;
    Dist[StartIdx][StartNode]=0;
    pq.push({0,StartNode});
    
    while(!pq.empty())
    {
        auto [Cost,Cur]=pq.top();
        pq.pop();
        if(Cost > Dist[StartIdx][Cur]) continue;
        
        for(auto& [W,Nxt] : Adj[Cur])
        {
            int NxtCost=W+Cost;
            if(NxtCost < Dist[StartIdx][Nxt])
            {
                Dist[StartIdx][Nxt]=NxtCost;
                pq.push({NxtCost,Nxt});
            }
        }
    }
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    cin>>N>>M>>K;
    
    Market.resize(K);
    for(auto& m : Market) cin>>m;
    
    Adj.resize(N+1);
    Dist.assign(K,vector<int>(N+1,1e9));
    while(M--)
    {
        int F,T,W;
        cin>>F>>T>>W;
        
        Adj[F].push_back({W,T});
        Adj[T].push_back({W,F});
    }
    for(int i=0;i<K;++i) Dijkstra(i,Market[i]);
    
    
    vector<vector<int>> Min(K,vector<int>(K,1e9));
    for(int S=0;S<K;++S)
    {
        Dp.assign((1<<K),vector<int>(K,1e9));
        Dp[1<<S][S]=0;
        for(int Mask=1;Mask<(1<<K);++Mask)
        {
            for(int Cur=0;Cur<K;++Cur)
            {
                if(!(Mask&(1<<Cur)) || Dp[Mask][Cur]==1e9) continue;
                
                for(int Nxt=0;Nxt<K;++Nxt)
                {
                    if(Mask&(1<<Nxt)) continue;
                    if(Dist[Cur][Market[Nxt]]==1e9) continue;
                    int NxtMask=Mask|(1<<Nxt);
                    Dp[NxtMask][Nxt]=min(Dp[NxtMask][Nxt],Dp[Mask][Cur]+Dist[Cur][Market[Nxt]]); 
                }
            }
        }
        for(int E=0;E<K;++E)
        {
            Min[S][E]=Dp[(1<<K)-1][E];
        }
    }
    
    
    int Ans=1e9;
    for(int s=1;s<=N;++s)
    {
        bool bShouldSkip=false;
        for(int m : Market) if(m==s) bShouldSkip=true;
        if(bShouldSkip) continue;
        
        for(int i=0;i<K;++i)
        {
            for(int j=0;j<K;++j)
            {
                if(Min[i][j]==1e9 || Dist[i][s]==1e9 || Dist[j][s]==1e9) continue;
                Ans=min(Ans,Dist[i][s]+Min[i][j]+Dist[j][s]);
            }
        }
    }
    cout<<Ans;
}