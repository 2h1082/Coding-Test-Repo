#include <bits/stdc++.h>

using namespace std;
vector<vector<int>> Graph;
vector<int> Discover, Low;
vector<bool> OnStack;
stack<int> st;
vector<vector<int>> SCCs;
int DFSCnt=0;

void DFS(int Cur)
{
    Discover[Cur]=Low[Cur]=++DFSCnt;
    st.push(Cur);
    OnStack[Cur]=true;
    
    for(int Next : Graph[Cur])
    {
        if(!Discover[Next])
        {
            DFS(Next);
            Low[Cur]=min(Low[Cur],Low[Next]);
        }
        else if(OnStack[Next])
        {
            Low[Cur]=min(Low[Cur],Discover[Next]);
        }
    }
    if(Low[Cur]==Discover[Cur])
    {
        vector<int> SCC;
        while(1)
        {
            int u=st.top();
            st.pop();
            OnStack[u]=false;
            SCC.push_back(u);
            if(u==Cur) break;
        }
        sort(SCC.begin(),SCC.end());
        SCCs.push_back(SCC);
    }
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int V, E;
    cin>>V>>E;
    Graph.resize(V+1);
    Discover.assign(V+1,0);
    Low.assign(V+1,0);
    OnStack.assign(V+1,false);
    while(E--)
    {
        int From,To;
        cin>>From>>To;
        Graph[From].push_back(To);
    }
    for(int i=1;i<=V;++i)
    {
        if(!Discover[i]) DFS(i);
    }
    sort(SCCs.begin(),SCCs.end());
    
    cout<<SCCs.size()<<"\n";
    for(auto& Comp : SCCs)
    {
        for(int v : Comp)
        {
            cout<<v<<" ";
        }
        cout<<"-1\n";
    }
}