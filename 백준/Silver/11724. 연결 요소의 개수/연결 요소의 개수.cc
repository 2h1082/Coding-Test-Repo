#include <iostream>
#include <vector>
#include <set>

using namespace std;
void DFS(vector<bool>& Visited, vector<set<int>>& G, int Cur)
{
    Visited[Cur]=true;
    for(auto& Vertex:G[Cur])
    {
        if(!Visited[Vertex])
        {
             DFS(Visited,G,Vertex);   
        }
    }
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int N=0,M=0;
    cin>>N>>M;
    vector<set<int>> G(N+1);
    vector<bool> Visited(N+1,false);
    while(M--)
    {
        int From=0,To=0;
        cin>>From>>To;
        G[From].insert(To);
        G[To].insert(From);
    }
    int Result=0;
    for(int i=1;i<N+1;++i)
    {
        if(!Visited[i])
        {
            DFS(Visited,G,i);
            Result++;
        }
    }
    cout<<Result;
}
