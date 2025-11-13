#include <bits/stdc++.h>
using namespace std;

vector<vector<int>> Adj;
vector<int> Low, Dis, SccId;
vector<bool> OnStack;
stack<int> st;
int Cnt=0, SccCnt=0;
int n,m;

int Idx(int x)
{
    if(x<0) return -x+n;
    else    return x;
}
int Not(int x)
{
    if(x>n) return x-n;
    else    return x+n;
}

void DFS(int Cur)
{
    Dis[Cur]=Low[Cur]=++Cnt;
    OnStack[Cur]=true;
    st.push(Cur);
    for(auto& Nxt : Adj[Cur])
    {
        if(!Dis[Nxt])
        {
            DFS(Nxt);
            Low[Cur]=min(Low[Cur],Low[Nxt]);
        }
        else if(OnStack[Nxt])
        {
            Low[Cur]=min(Low[Cur],Dis[Nxt]);
        }
    }
    if(Dis[Cur]==Low[Cur])
    {
        while(1)
        {
            int v=st.top();
            st.pop();
            OnStack[v]=false;
            SccId[v]=SccCnt;
            if(v==Cur) break;
        }
        ++SccCnt;
    }
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    
    while(cin>>n>>m)
    {
        Low.assign(2*n+1,0);
        Dis.assign(2*n+1,0);
        SccId.assign(2*n+1,0);
        OnStack.assign(2*n+1,false);
        Adj.assign(2*n+1,{});
        while(m--)
        {
            int a,b;
            cin>>a>>b;
            a=Idx(a);
            b=Idx(b);
            Adj[Not(a)].push_back(b);
            Adj[Not(b)].push_back(a);
        }
        // 상근이가 반드시 통과해야 하는 문제
        // 1번의 거짓이 참이면 1번도 반드시 참이 되도록하여 해당 간선
        Adj[Not(1)].push_back(1);
        
        for(int i=1;i<=2*n;++i)
            if(!Dis[i]) DFS(i);
        
        bool bIsPossible=true;
        for(int i=1;i<=2*n;++i)
        {
            if(SccId[i]==SccId[Not(i)])
            {
                bIsPossible=false;
            }
        }
        cout<<( bIsPossible? "yes" : "no" )<<'\n';
    }
}