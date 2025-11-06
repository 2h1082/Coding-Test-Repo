#include <bits/stdc++.h>

using namespace std;
using ll=long long;

class SegTree
{
private: 
    vector<ll> Tree;
    int Size=0;
public:
    SegTree(int N) { Tree.assign(4*N,0); }
    void Update (int Node, int S, int E, int Idx)
    {
        if(S==E) 
        {
            Tree[Node]++;
            return;
        }
        int M=(S+E)/2;
        if(Idx<=M) Update(Node*2,S,M,Idx);
        else       Update(Node*2+1,M+1,E,Idx);
        Tree[Node]=Tree[Node*2]+Tree[Node*2+1];
    }
    ll Query(int Node, int S, int E, int L, int R)
    {
        if(R<S||L>E) return 0;
        if(L<=S&&E<=R) return Tree[Node];
        int M=(S+E)/2;
        return Query(Node*2,S,M,L,R)+Query(Node*2+1,M+1,E,L,R);
    }
};
int main()
{
    int N;
    cin>>N;
    vector<int> A(N), B(N);
    
    for(auto& a : A) cin>>a;
    for(auto& b : B) cin>>b;
    
    unordered_map<int,int> Pos;
    for(int i=0;i<N;++i)
    {
        Pos[A[i]]=i+1;
    }
    vector<int> Arr(N);
    for(int i=0;i<N;++i)
    {
        Arr[i]=Pos[B[i]];
    }
    ll Ans=0;
    SegTree Seg(N);
    for(int i=0;i<N;++i)
    {
        Ans+=Seg.Query(1,1,N,Arr[i]+1,N);
        Seg.Update(1,1,N,Arr[i]);
    }
    cout<<Ans;
}