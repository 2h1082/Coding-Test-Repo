#include <bits/stdc++.h>

using namespace std;

vector<vector<int>> DP, F;

void DFS(int Cur, int Parent)
{
    DP[Cur][0]=0;
    DP[Cur][1]=1;
    
    for(int Next:F[Cur])
    {
        if(Next==Parent) continue;
        DFS(Next,Cur);
        DP[Cur][0]+=DP[Next][1];
        DP[Cur][1]+=min(DP[Next][0],DP[Next][1]);
    }
}
int main()
{
    int N=0;
    cin>>N;
    
    DP.assign(N+1,vector<int>(2,0));
    F.resize(N+1);
    for(int i=1;i<N;++i)
    {
        int u,v;
        cin>>u>>v;
        F[u].push_back(v);
        F[v].push_back(u);
    }
    DFS(1,0);
    cout<<min(DP[1][0],DP[1][1]);
}