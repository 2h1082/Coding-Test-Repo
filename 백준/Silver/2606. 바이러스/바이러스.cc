#include <vector>
#include <iostream>
using namespace std;
void DFS(int& answer, vector<vector<int>>& graph, vector<bool>& visited, int cur)
{
    if(visited[cur]) return;
    visited[cur]=true;
    for(auto node: graph[cur])
    {
        if(!visited[node])
        {
            answer++;
            DFS(answer,graph,visited,node);
        }
    }
}
int main()
{
    int answer=0;
    int n=0;
    cin>>n;
    vector<vector<int>> graph(n);
    vector<bool> visited(n,false);
    int cnt=0;
    cin>>cnt;
    for(int i=0;i<cnt;i++)
    {
        int from=0, to=0;
        cin>>from>>to;
        graph[from-1].push_back(to-1);
        graph[to-1].push_back(from-1);
    }
    DFS(answer,graph,visited,0);
    cout<<answer;
    return 0;
}