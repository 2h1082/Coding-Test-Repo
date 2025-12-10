#include "bits/stdc++.h"
using namespace std;

vector<int> G, Visited;
vector<bool> bIsCycle;
void DFS(int Cur, int Par)
{
    Visited[Cur]=1;
    int Nxt=G[Cur];
    if(!Visited[Nxt]) DFS(Nxt,Cur);
    else if(Visited[Nxt]==1)
    {
        int Start=Nxt;
        while(1)
        {
            bIsCycle[Nxt]=true;
            Nxt=G[Nxt];
            if(Start==Nxt) break;
        }
    }
    Visited[Cur]=2;
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    int N;
    cin>>N;
    G.assign(N+1,0);
    Visited.assign(N+1,0);
    bIsCycle.assign(N+1,false);
    for(int i=1;i<=N;++i)
    {
        cin>>G[i];
    }
    
    for(int i=1;i<=N;++i) 
    {
        if(!Visited[i]) DFS(i,0);
    }
    
    int Cnt=0;
    for(int i=1;i<=N;++i) 
    {
        if(bIsCycle[i]) Cnt++;
    }
    cout<<Cnt<<'\n';
    for(int i=1;i<=N;++i) 
    {
        if(bIsCycle[i]) cout<<i<<'\n';
    }
}