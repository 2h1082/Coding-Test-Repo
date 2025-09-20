#include <iostream>
#include <vector>

using namespace std;
int N=0;
vector<int> Parent;
vector<bool> Visited;
vector<vector<int>> Tree;
void DFS(int Cur)
{
    for(auto& Node:Tree[Cur])
    {
        if(Visited[Node]) continue;
        Visited[Node]=true;
        Parent[Node]=Cur;
        DFS(Node);
    }
}
int main()
{
    cin>>N;
    Parent.assign(N+1,1);
    Visited.assign(N+1,false);
    Tree.assign(N+1,vector<int>());
    for(int i=0;i<N-1;++i)
    {
        int A, B;
        cin>>A>>B;
        Tree[A].push_back(B);
        Tree[B].push_back(A);
    }
    Visited[1]=true;
    DFS(1);
    for(int i=2;i<=N;++i)
    {
        cout<<Parent[i]<<"\n";
    }
}