#include <bits/stdc++.h>

using namespace std;

vector<vector<int>> Tree;
int DFS(int Parent, int Cur, vector<int>& DP)
{
    int NodeCnt=1;
    for(auto& Next : Tree[Cur])
    {
        if(Next==Parent) continue;
        NodeCnt+=DFS(Cur,Next,DP);
    }
    DP[Cur]=NodeCnt;
    return NodeCnt;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    int N=0,R=0,Q=0;
    cin>>N>>R>>Q;
    Tree.assign(N+1,vector<int>());
    for(int i=1;i<N;++i)
    {
        int F, T;
        cin>>F>>T;
        Tree[F].push_back(T);
        Tree[T].push_back(F);
    }
    vector<int> DP(N+1,1);
    DFS(0,R,DP);
    while(Q--)
    {
        int U=0;
        cin>>U;
        
        
        cout<<DP[U]<<"\n";
    }
}