#include "bits/stdc++.h"
using namespace std;

vector<bool> Used, bIsLeaf;
vector<int> UsedEdge;
vector<vector<int>> CompNode, CompEdge;
vector<vector<pair<int,int>>> Adj;
int CompNum=0;
void DFS(int Cur, vector<int>& Node, vector<int>& Edge)
{
    Used[Cur]=true;
    bIsLeaf[Cur]=true;
    Node.push_back(Cur);
    for(auto& [Nxt,Id] : Adj[Cur])
    {
        if(!Used[Nxt])
        {
            if(bIsLeaf[Cur]) bIsLeaf[Cur]=false;
            Edge.push_back(Id);
            UsedEdge[Nxt]=Id;
            DFS(Nxt,Node,Edge);
        }
    }
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    int N,M;
    cin>>N>>M;
    
    Adj.resize(N+1);
    UsedEdge.assign(N+1,-1);
    Used.assign(N+1,false);
    bIsLeaf.assign(N+1,false);
        
    for(int i=1;i<=M;++i)
    {
        int U,V;
        cin>>U>>V;
        
        Adj[U].push_back({V,i});
        Adj[V].push_back({U,i});
    }
    if(N<=2)
    {
        cout<<-1;
        return 0;
    }
    
    CompNode.push_back({});
    CompEdge.push_back({});
    for(int i=1;i<=N;++i)
    {
        if(!Used[i]) 
        {
            DFS(i,CompNode[CompNum],CompEdge[CompNum]);
            ++CompNum;
            CompNode.push_back({});
            CompEdge.push_back({});
        }
    }
    
    if(CompNum > 2)
    {
        cout<<-1;
        return 0;
    }
    
    if(CompNum==1)
    {
        int LeafNode=-1;
        for(int i=1;i<=N;++i)
        {
            if(bIsLeaf[i])
            {
                LeafNode=i;
                break;
            }
        }
        
        cout<<N-1<<' '<<1<<'\n';
        for(int Node : CompNode[0]) 
        {
            if(Node==LeafNode) continue;
            cout<<Node<<' ';
        }
        cout<<'\n';
        for(int Edge : CompEdge[0])
        {
            if(Edge==UsedEdge[LeafNode]) continue;
            cout<<Edge<<' ';
        }
        cout<<'\n';
        
        cout<<LeafNode<<"\n\n";
    }
    else if(CompNum==2 && CompNode[0].size() != CompNode[1].size())
    {
        cout<<CompNode[0].size()<<' '<<CompNode[1].size()<<'\n';
        for(int i=0;i<2;++i)
        {
            for(int Node : CompNode[i]) cout<<Node<<' ';
            cout<<'\n';
            for(int Edge : CompEdge[i]) cout<<Edge<<' ';
            cout<<'\n';
        }
    }
    else
    {
        cout<<-1;
    }
}