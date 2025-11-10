#include <bits/stdc++.h>
using namespace std;
using ll=long long;

int N,M;
vector<vector<int>> Adj;
vector<int> D, L, SccId;
vector<bool> OnStack;
stack<int> st;
int SccCnt=0, Cnt=0;
int Idx(int x)
{
    if(x<0) return -x+N;
    else    return x;
}
int Not(int x)
{
    if(x>N) return x-N;
    else    return x+N;
}
void DFS(int v)
{
    D[v]=L[v]=++Cnt;
    OnStack[v]=true;
    st.push(v);
    for(auto& Nxt : Adj[v])
    {
        if(!D[Nxt])
        {
            DFS(Nxt);
            L[v]=min(L[v],L[Nxt]);
        }
        else if(OnStack[Nxt])
        {
            L[v]=min(L[v],D[Nxt]);
        }
    }
    if(D[v]==L[v])
    {
        while(1)
        {
            int Cur=st.top();
            st.pop();
            OnStack[Cur]=false;
            SccId[Cur]=SccCnt;
            if(v==Cur) break;
        }
        SccCnt++;
    }
    return;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cin>>N>>M;
    Adj.assign(2*N+1,{});
    D.assign(2*N+1,0);
    SccId.assign(2*N+1,0);
    OnStack.assign(2*N+1,false);
    L.assign(2*N+1,0);
    while(M--)
    {
        int A,B;
        cin>>A>>B;
        A=Idx(A);
        B=Idx(B);
        Adj[Not(A)].push_back(B);
        Adj[Not(B)].push_back(A);
    }
    for(int i=1;i<=2*N;++i)
    {
        if(!D[i]) DFS(i);
    }
    
    for(int i=1;i<=N;++i)
    {
        if(SccId[i]==SccId[Not(i)]) 
        {
            cout<<0;
            return 0;
        }
    }
    vector<int> Ans(N+1,0);
    for(int i=1;i<=N;++i)
    {
        Ans[i]=(SccId[i]<SccId[Not(i)]) ? 1 : 0;
    }
    cout<<1<<'\n';
    for(int i=1;i<=N;++i)
    {
        cout<<Ans[i]<<" ";
    }
}