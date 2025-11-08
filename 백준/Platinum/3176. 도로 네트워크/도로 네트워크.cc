#include <bits/stdc++.h>

using namespace std;
vector<vector<pair<int,int>>> Graph;
vector<vector<int>> Min, Max, Parent;
vector<int> Depth;
int Log=18;
void DFS(int Cur, int Par)
{
    for(auto& [W, Nxt]: Graph[Cur])
    {
        if(Par==Nxt) continue;
        Parent[Nxt][0]=Cur;
        Min[Nxt][0]=min(Min[Nxt][0],W);
        Max[Nxt][0]=max(Max[Nxt][0],W);
        Depth[Nxt]=Depth[Cur]+1;
        DFS(Nxt,Cur);
    }
}

pair<int,int> LCA(int A, int B)
{
    if(Depth[A]<Depth[B]) swap(A,B);
    
    int MinW=1e9, MaxW=0;
    for(int k=Log-1;k>=0;--k)
    {
        if(Depth[A]-(1<<k)>=Depth[B])
        {
            MinW=min(MinW,Min[A][k]);
            MaxW=max(MaxW,Max[A][k]);
            A=Parent[A][k];
        }
    }
    if(A==B) return {MinW,MaxW};
    
    for(int k=Log-1;k>=0;--k)
    {
        if(Parent[A][k]!=Parent[B][k])
        {
            MinW=min({MinW,Min[A][k],Min[B][k]});
            MaxW=max({MaxW,Max[A][k],Max[B][k]});
            A=Parent[A][k];
            B=Parent[B][k];
        }
    }
    MinW=min({MinW,Min[A][0],Min[B][0]});
    MaxW=max({MaxW,Max[A][0],Max[B][0]});
    return {MinW,MaxW};
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int N=0;
    cin>>N;
    Graph.assign(N+1,{});
    Depth.assign(N+1,0);
    Parent.assign(N+1,vector<int>(Log,0));
    Min.assign(N+1,vector<int>(Log,1e9));
    Max.assign(N+1,vector<int>(Log,0));
    for(int i=1;i<N;++i)
    {
        int A,B,C;
        cin>>A>>B>>C;
        Graph[A].push_back({C,B});
        Graph[B].push_back({C,A});
    }
    DFS(1,0);
    
    for(int k=1;k<Log;++k)
    {
        for(int i=1;i<=N;++i)
        {
            int Mid=Parent[i][k-1];
            if(Mid==0) continue;
            Parent[i][k]=Parent[Mid][k-1];
            Min[i][k]=min(Min[Mid][k-1],Min[i][k-1]);
            Max[i][k]=max(Max[Mid][k-1],Max[i][k-1]);
        }
    }
    int K=0;
    cin>>K;
    while(K--)
    {
        int D, E;
        cin>>D>>E;
        auto [MinVal, MaxVal]=LCA(D,E);
        cout<<MinVal<<" "<<MaxVal<<"\n";
    }
}