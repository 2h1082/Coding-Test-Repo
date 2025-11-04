#include <bits/stdc++.h>

using namespace std;
using ll=long long;

int N,M,K;
int Mod=1000000007;
vector<int> Nums;
vector<ll> Tree;
ll Build(int Node, int S, int E)
{
    if(S==E) return Tree[Node]=Nums[S];
    
    int Mid=(S+E)/2;
    return Tree[Node]=Build(Node*2,S,Mid)*Build(Node*2+1,Mid+1,E)%Mod;
}

ll Query(int Node, int S, int E, int L, int R)
{
    if(R<S || L>E) return 1;
    if(L<=S&&E<=R) return Tree[Node];
    
    int Mid=(S+E)/2;
    return Query(Node*2,S,Mid,L,R)*Query(Node*2+1,Mid+1,E,L,R)%Mod;
}

void UpdateNode(int Node, int S, int E, int Idx, int NewVal)
{
    if(Idx<S||Idx>E) return;
    if(S==E)
    {
        Tree[Node]=Nums[Idx]=NewVal;
        return;
    }
    
    int Mid=(S+E)/2;
    UpdateNode(Node*2,S,Mid,Idx,NewVal);
    UpdateNode(Node*2+1,Mid+1,E,Idx,NewVal);
    Tree[Node]=(Tree[Node*2]*Tree[Node*2+1])%Mod;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    cin>>N>>M>>K;
    Nums.assign(N+1,0);
    Tree.assign(4*N,0);
    for(int i=1;i<=N;++i)
    {
        cin>>Nums[i];
    }
    Build(1,1,N);
    
    for(int i=0;i<M+K;++i)
    {
        int Com=0, a, b;
        cin>>Com>>a>>b;
        if(Com==1)
        {
            UpdateNode(1,1,N,a,b);
        }
        else if(Com==2)
        {
            cout<<Query(1,1,N,a,b)<<"\n";
        }
    }
}