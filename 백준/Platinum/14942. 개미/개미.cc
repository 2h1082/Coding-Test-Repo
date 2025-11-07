#include <bits/stdc++.h>

using namespace std;
using ll=long long;
vector<vector<pair<int,int>>> Graph;
vector<int> Energy, Depth;
vector<vector<int>> Parent;
vector<vector<ll>> Dist;
int Log=18;
void DFS(int Cur, int Par)
{
    for(auto& [W,Nxt]:Graph[Cur])
    {
        if(Nxt==Par) continue;
        Parent[Nxt][0]=Cur;
        Dist[Nxt][0]=W;
        Depth[Nxt]=Depth[Cur]+1;
        DFS(Nxt,Cur);
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int N=0;
    cin>>N;
    
    Energy.assign(N+1,0);
    Depth.assign(N+1,0);
    Parent.assign(N+1,vector<int>(Log,0));
    Dist.assign(N+1,vector<ll>(Log,0));
    for(int i=1;i<=N;++i)
    {
        cin>>Energy[i];
    }
    
    Graph.assign(N+1,{});
    for(int i=1;i<N;++i)
    {
        int a,b,c;
        cin>>a>>b>>c;
        Graph[a].push_back({c,b});
        Graph[b].push_back({c,a});
    }
    DFS(1,0);
    
    for(int k=1;k<Log;++k)
    {
        for(int i=1;i<=N;++i)
        {
            Parent[i][k]=Parent[Parent[i][k-1]][k-1];
            Dist[i][k]=Dist[i][k-1]+Dist[Parent[i][k-1]][k-1];
        }
    }
    
    for(int i=1;i<=N;++i)
    {
        ll energy=Energy[i];
        int Cur=i;
        for(int k=Log-1;k>=0;--k)
        {
            if(Parent[Cur][k]&&Dist[Cur][k]<=energy)
            {
                energy-=Dist[Cur][k];
                Cur=Parent[Cur][k];
            }
        }
        cout<<Cur<<"\n";
    }
}