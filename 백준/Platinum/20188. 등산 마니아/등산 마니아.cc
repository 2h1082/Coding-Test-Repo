#include "bits/stdc++.h"
using namespace std;
using ll=long long;
vector<ll> SubTreeSize;
vector<vector<int>> A;

void DFS(int Cur, int Prev)
{
    SubTreeSize[Cur]=1;
    for(int Nxt : A[Cur])
    {
        if(Nxt==Prev) continue;
        DFS(Nxt,Cur);
        SubTreeSize[Cur]+=SubTreeSize[Nxt];
    }
}
ll Combination(int Num)
{
    if(Num<2) return 0;
    return 1LL*Num*(Num-1)/2;
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    int N;
    cin>>N;
    
    A.resize(N+1);
    SubTreeSize.resize(N+1,0);
    for(int i=1;i<N;++i)
    {
        int U,V;
        cin>>U>>V;
        
        A[U].push_back(V);
        A[V].push_back(U);
    }
    DFS(1,0);
    
    ll Ans=0;
    for(int i=2;i<=N;++i)
    {
        ll K=SubTreeSize[i];
        Ans+=Combination(N)-Combination(N-K);
    }
    cout<<Ans;
}