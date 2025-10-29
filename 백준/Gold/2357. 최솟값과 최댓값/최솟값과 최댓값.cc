#include <bits/stdc++.h>

using namespace std;
vector<int> Nums;
vector<pair<int,int>> Tree;

pair<int,int> Build(int Node, int Start, int End)
{
    if(Start==End)
    {
        return Tree[Node]={Nums[Start],Nums[Start]};
    }
    int Mid=(Start+End)/2;
    auto p1=Build(Node*2,Start,Mid);
    auto p2=Build(Node*2+1,Mid+1,End);
    Tree[Node]={min(p1.first,p2.first),max(p1.second,p2.second)};
    return Tree[Node];
}

pair<int,int> Query(int Node, int Start, int End, int L, int R)
{
    if(R<Start||L>End) return pair<int,int>(1e9,0);
    if(L<=Start&&End<=R) return Tree[Node];
    int Mid=(End+Start)/2;
    auto p1=Query(Node*2,Start,Mid,L,R);
    auto p2=Query(Node*2+1,Mid+1,End,L,R);
    return {min(p1.first,p2.first),max(p1.second,p2.second)};
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int N,M;
    cin>>N>>M;
    
    Nums.resize(N+1);
    Tree.resize(4*N);
    for(int i=1;i<=N;++i)
    {
        cin>>Nums[i];
    }
    Build(1,1,N);
    while(M--)
    {
        int a,b;
        cin>>a>>b;
        auto [Min,Max]=Query(1,1,N,a,b);
        cout<<Min<<" "<<Max<<"\n";
    }
}