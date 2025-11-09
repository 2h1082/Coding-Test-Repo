#include <bits/stdc++.h>

using namespace std;
vector<vector<int>> Adj;
vector<pair<int,int>> Edges;
vector<int> Low, Idx, Ans;
int Cnt=0;

void DFS(int Cur, int Par)
{
    Low[Cur]=Idx[Cur]=++Cnt;
    int ChildCnt=0;
    for(auto& Nxt : Adj[Cur])
    {
        if(Nxt==Par) continue;
        if(!Idx[Nxt])
        {
            ChildCnt++;
            DFS(Nxt,Cur);
            Low[Cur]=min(Low[Cur],Low[Nxt]);
            if(Low[Nxt]>Idx[Cur]) Edges.push_back({min(Cur,Nxt),max(Cur,Nxt)});
        }
        else
        {
            Low[Cur]=min(Low[Cur],Idx[Nxt]);
        }
    }  
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int V, E;
    cin>>V>>E;
    Adj.assign(V+1,{});
    Low.assign(V+1,0);
    Idx.assign(V+1,0);
    while(E--)
    {
        int A,B;
        cin>>A>>B;
        Adj[A].push_back(B);
        Adj[B].push_back(A);
    }
    for(int i=1;i<=V;++i)
    {
        if(!Idx[i]) DFS(i,-1);
    }
    
    sort(Edges.begin(),Edges.end());
    cout<<Edges.size()<<"\n";
    for(auto [a,b]:Edges)
    {
        cout<<a<<" "<<b<<"\n";
    }
}