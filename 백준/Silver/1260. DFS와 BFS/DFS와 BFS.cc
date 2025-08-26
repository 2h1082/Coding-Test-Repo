#include <iostream>
#include <vector>
#include <queue>
#include <set>

using namespace std;

int N=0,M=0,V=0;
void BFS(vector<set<int>>& Graph, vector<bool>& Visited, int Start)
{
    queue<int> q;
    q.push(Start);
    Visited[Start]=true;
    while(!q.empty())
    {
        int Cur=q.front();
        q.pop();
        cout<<Cur<<" ";
        for(auto& P:Graph[Cur])
        {
            if(!Visited[P])
            {
                Visited[P]=true;
                q.push(P);
            }
        }
    }
}
void DFS(vector<set<int>>& Graph, vector<bool>& Visited, int Cur)
{
    cout<<Cur<<" ";
    Visited[Cur]=true;
    for(auto& NextV:Graph[Cur])
    {
        if(!Visited[NextV])
        {
            DFS(Graph,Visited,NextV);
        }
    }
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin>>N>>M>>V;
    
    vector<set<int>> Graph(N+1);
    while(M--)
    {
        int From=0, To=0;
        cin>>From>>To;
        Graph[From].insert(To);
        Graph[To].insert(From);
    }
    vector<bool> Visited(N+1,false);
    DFS(Graph,Visited,V);
    cout<<"\n";
    fill(Visited.begin(), Visited.end(), false);
    BFS(Graph,Visited,V);
}