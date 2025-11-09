#include <bits/stdc++.h>

using namespace std;

int N,M;
vector<vector<int>> Graph;
vector<int> Low, Discover, SccId;
vector<bool> OnStack;
stack<int> st;
int Cnt=0, SccCnt=0;
int Idx(int x)
{
    if(x>0) return x;
    else    return -x+N;
}
int Not(int x)
{
    if(x>N) return x-N;
    else    return x+N;
}
void DFS(int Cur)
{
    Discover[Cur]=Low[Cur]=++Cnt;
    st.push(Cur);
    OnStack[Cur]=true;
    for(int Nxt : Graph[Cur])
    {
        if(!Discover[Nxt])
        {
            DFS(Nxt);
            Low[Cur]=min(Low[Cur],Low[Nxt]);
        }
        else if(OnStack[Nxt])
        {
            Low[Cur]=min(Low[Cur],Discover[Nxt]);
        }
    }
    
    if(Low[Cur]==Discover[Cur])
    {
        while(1)
        {
            int t=st.top();
            st.pop();
            OnStack[t]=false;
            SccId[t]=SccCnt;
            if(t==Cur) break;
        }
        SccCnt++;
    }
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    cin>>N>>M;
    Graph.assign(2*N+1,{});
    Low.assign(2*N+1,0);
    Discover.assign(2*N+1,0);
    SccId.assign(2*N+1,0);
    OnStack.assign(2*N+1,false);
    while(M--)
    {
        int A,B;
        cin>>A>>B;
        A=Idx(A);
        B=Idx(B);
        Graph[Not(A)].push_back(B);
        Graph[Not(B)].push_back(A);
    }
    
    for(int i=1;i<=2*N;++i)
    {
        if(!Discover[i]) DFS(i);
    }
    for(int i=1;i<=N;++i)
    {
        if(SccId[i]==SccId[Not(i)])
        {
            cout<< 0;
            return 0;
        }
    }
    cout<<1;
}