#include <bits/stdc++.h>

using namespace std;
int N,M;
vector<vector<int>> Graph;
vector<vector<int>> P;
vector<int> D;
int MaxDepth=18;
void DFS(int Cur, int Parent, int Depth)
{
    P[Cur][0]=Parent;
    D[Cur]=Depth;
    for(auto& Nxt : Graph[Cur])
    {
        if(Parent==Nxt) continue;
        DFS(Nxt,Cur,Depth+1);
    }
}

int LCA(int v1, int v2)
{
    if(D[v1]<D[v2]) swap(v1,v2);
    
    for(int k=MaxDepth-1;k>=0;--k)
    {
        if(D[v1]-(1<<k)>=D[v2])
        {
            v1=P[v1][k];
        }
    }
    if(v1==v2) return v1;
    
    for(int k=MaxDepth-1;k>=0;--k)
    {
        if(P[v1][k]!=P[v2][k])
        {
            v1=P[v1][k];
            v2=P[v2][k];
        }
    }
    return P[v1][0];
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    cin>>N;
    Graph.assign(N+1,vector<int>());
    P.assign(N+1,vector<int>(MaxDepth,0));
    D.assign(N+1,0);
    for(int i=1;i<N;++i)
    {
        int From,To;
        cin>>From>>To;
        Graph[From].push_back(To);
        Graph[To].push_back(From);
    }
    DFS(1,0,0);
    for(int k=1;k<MaxDepth;++k)
    {
        for(int i=1;i<=N;++i)
        {
            P[i][k]=P[P[i][k-1]][k-1];
        }
    }
    cin>>M;
    while(M--)
    {
        int A, B;
        cin>>A>>B;
        cout<<LCA(A,B)<<"\n";
    }
}