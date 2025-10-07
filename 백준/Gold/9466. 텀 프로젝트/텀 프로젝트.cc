#include <iostream>
#include <vector>

using namespace std;
int Count=0;
void DFS(vector<int>& Graph, vector<int>& Visited, int Idx)
{
    Visited[Idx]=1;
    int Next = Graph[Idx];
    if(Visited[Next]==1) 
    {
        for(int i=Next;i!=Idx;i=Graph[i])
        {
            if(Visited[i]==1) Count--;
        }
        Count--;
    }
    if(Visited[Next]==0) DFS(Graph,Visited,Next);
    Visited[Idx]=2;
}
int main()
{
    int T=0;
    cin>>T;
    while(T--)
    {
        int N=0;
        cin>>N;
        vector<int> Graph(N+1,0);
        vector<int> Visited(N+1,0); // 0: Unvisited, 1: Current Path, 2: Visited
        for(int i=1;i<=N;++i)
        {
            cin>>Graph[i];
        }
        Count=N;
        for(int i=1;i<=N;++i)
        {
            if(!Visited[i])
            {
                DFS(Graph,Visited,i);
            }
        }
        cout<<Count<<"\n";
    }
}