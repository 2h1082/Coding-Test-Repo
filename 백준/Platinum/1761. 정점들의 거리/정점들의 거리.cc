#include <bits/stdc++.h>

using namespace std;
using ll=long long;

vector<vector<pair<int,int>>> Graph;
vector<ll> Dists;
vector<int> Depths;
vector<vector<int>> Parents;
int MaxDepth=17;
void DFS(int Cur, int Parent, int Depth, ll Dist)
{
    Dists[Cur]=Dist;
    Depths[Cur]=Depth;
    Parents[Cur][0]=Parent;
    for(auto& [Next,Cost] : Graph[Cur])
    {
        if(Next==Parent) continue;
        DFS(Next,Cur,Depth+1,Dist+Cost);
    }
}
int LCA(int A, int B)
{
    if(Depths[A]<Depths[B]) swap(A,B);
    
    for(int k=MaxDepth-1;k>=0;--k)
    {
        if(Depths[A]-(1<<k)>=Depths[B])
        {
            A=Parents[A][k];
        }
    }
    if(A==B) return A;
    
    for(int k=MaxDepth-1;k>=0;--k)
    {
        if(Parents[A][k]!=Parents[B][k])
        {
            A=Parents[A][k];
            B=Parents[B][k];
        }
    }
    return Parents[A][0];
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int N=0;
    cin>>N;
    Dists.resize(N+1);
    Depths.resize(N+1);
    Parents.assign(N+1,vector<int>(MaxDepth));
    Graph.resize(N+1);
    
    for(int i=1;i<N;++i)
    {
        int F,T,C;
        cin>>F>>T>>C;
        Graph[F].push_back({T,C});
        Graph[T].push_back({F,C});
    }
    DFS(1,0,0,0);
    for(int k=1;k<MaxDepth;++k)
    {
        for(int v=1;v<=N;++v)
        {
            Parents[v][k]=Parents[Parents[v][k-1]][k-1];
        }
    }
    
    int M=0;
    cin>>M;
    while(M--)
    {
        int F, T;
        cin>>F>>T;
        int LCANode=LCA(F,T);
        cout<<Dists[F]+Dists[T]-2*Dists[LCANode]<<"\n";
    }
}