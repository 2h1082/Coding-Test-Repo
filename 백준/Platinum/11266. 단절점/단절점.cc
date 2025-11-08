#include <bits/stdc++.h>

using namespace std;
int V,E;
vector<vector<int>> Graph;
vector<int> Discover, Low;
vector<bool> CutNode;
int Cnt=0;
void DFS(int Cur, int Parent)
{
    Discover[Cur]=Low[Cur]=++Cnt;
    int ChildCnt=0;
    for(auto& Nxt : Graph[Cur])
    {
        if(Nxt==Parent) continue;
        if(!Discover[Nxt])
        {
            ChildCnt++;
            DFS(Nxt,Cur);
            Low[Cur]=min(Low[Cur],Low[Nxt]);
            if(Parent!=-1&&Low[Nxt]>=Discover[Cur]) CutNode[Cur]=true;
        }
        else
        {
            Low[Cur]=min(Low[Cur],Discover[Nxt]);
        }
    }
    if(Parent==-1 && ChildCnt>=2) CutNode[Cur]=true;
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    cin>>V>>E;
    Graph.assign(V+1,{});
    Discover.assign(V+1,0);
    Low.assign(V+1,0);
    CutNode.assign(V+1,false);
    while(E--)
    {
        int V1,V2;
        cin>>V1>>V2;
        Graph[V1].push_back(V2);
        Graph[V2].push_back(V1);
    }
    for(int i=1;i<=V;++i)
    {
        if(!Discover[i]) DFS(i,-1);
    }
    vector<int> Ans;
    for(int i=1;i<=V;++i)
    {
        if(CutNode[i]) Ans.push_back(i);
    }
    cout<<Ans.size()<<"\n";
    for(auto& a : Ans) cout<<a<<" ";
}