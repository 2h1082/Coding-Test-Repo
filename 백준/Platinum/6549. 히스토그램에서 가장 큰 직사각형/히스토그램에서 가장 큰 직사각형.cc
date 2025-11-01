#include <bits/stdc++.h>

using namespace std;
using ll=long long;
int N=0;
vector<int> Nums;
vector<int> Tree;
int Build(int Node, int Start, int End)
{
    if(Start==End)
    {
        return Tree[Node]=Start;
    }
    int Mid=(Start+End)/2;
    int Left=Build(Node*2,Start,Mid);
    int Right=Build(Node*2+1,Mid+1,End);
    return Tree[Node]= (Nums[Left]<Nums[Right]) ? Left : Right;
}

int QueryMinIndex(int Node, int Start, int End, int L, int R)
{
    if(Start>R || End<L) return -1;
    if(L<=Start&&End<=R) return Tree[Node];
    int Mid=(Start+End)/2;
    int Left=QueryMinIndex(Node*2,Start,Mid,L,R);
    int Right=QueryMinIndex(Node*2+1,Mid+1,End,L,R);
    if(Left==-1) return Right;
    if(Right==-1) return Left;
    return (Nums[Left]<Nums[Right]) ? Left : Right;
}
ll GetMaxArea(int L, int R)
{
    if(L>R) return 0;
    int Index=QueryMinIndex(1,1,N,L,R);
    ll CurArea=1LL*Nums[Index]*(R-L+1);
    ll Left=GetMaxArea(L,Index-1);
    ll Right=GetMaxArea(Index+1,R);
    return max({CurArea,Left,Right});
}
int main()
{
    while(1)
    {
        cin>>N;
        if(!N) break;
        Nums.assign(N+1,0);
        Tree.assign(4*N,0);
        for(int i=1;i<=N;++i)
        {
            cin>>Nums[i];
        }
        Build(1,1,N);
        cout<<GetMaxArea(1,N)<<"\n";
    }
}