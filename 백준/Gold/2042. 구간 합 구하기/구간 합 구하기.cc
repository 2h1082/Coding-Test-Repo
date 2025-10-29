#include <bits/stdc++.h>

using namespace std;
using ll=long long;

vector<ll> Nums,Tree;

ll Build(int Node, int Start, int End)
{
    if(Start==End)
    {
        return Tree[Node]=Nums[Start];
    }
    ll Mid=(End+Start)/2;
    return Tree[Node]=Build(Node*2,Start,Mid)+Build(Node*2+1,Mid+1,End);
}

ll Query(int Node, int Start, int End, int L, int R)
{
    if(Start>R||End<L) return 0;
    if(L<=Start&&End<=R) return Tree[Node];
    ll Mid=(Start+End)/2;
    return Query(Node*2,Start,Mid,L,R)+Query(Node*2+1,Mid+1,End,L,R);
}

void Update(int Node, int Start, int End, int Idx, ll Diff)
{
    if(Idx<Start || Idx>End) return;
    Tree[Node]+=Diff;
    if(Start==End) return;
    
    ll Mid=(Start+End)/2;
    Update(Node*2,Start,Mid,Idx,Diff);
    Update(Node*2+1,Mid+1,End,Idx,Diff);
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    int N,M,K;
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
        ll a,b,c;
        cin>>a>>b>>c;
        if(a==1)
        {
            ll Diff=c-Nums[b];
            Nums[b]=c;
            Update(1,1,N,b,Diff);
        }
        else if(a==2)
        {
            cout<<Query(1,1,N,b,c)<<"\n";
        }
    }
}