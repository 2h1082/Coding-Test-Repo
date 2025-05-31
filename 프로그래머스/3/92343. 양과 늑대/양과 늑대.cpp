#include <bits/stdc++.h>

using namespace std;

int answer = 0;
void dfs(int sheep,int wolf,vector<bool>& visited, vector<int>& adj,vector<int>& info, vector<vector<int>>& graph)
{
    answer=max(answer,sheep);
    if(adj.empty()) return;
    
    for(int i=0;i<adj.size();i++)
    {
        int next=adj[i];
        int prevsheep=sheep;
        int prevwolf=wolf;
        vector<int> prevadj=adj;
        vector<bool> prevVisited=visited;
        
        visited[next]=true;
        if(info[next]==0) sheep++;
        else              wolf++;
        
        if(wolf>=sheep)
        {
            sheep=prevsheep;
            wolf=prevwolf;
            adj=prevadj;
            visited=prevVisited;
            continue;
        }
        adj.erase(adj.begin()+i);
        for(int e:graph[next])
        {
            if(!visited[e])
            {
                adj.push_back(e);
            }
        }
        dfs(sheep,wolf,visited,adj,info,graph);
        
        sheep=prevsheep;
        wolf=prevwolf;
        adj=prevadj;
        visited=prevVisited;
    }
}

int solution(vector<int> info, vector<vector<int>> edges) {
    int n=info.size();
    vector<vector<int>> graph(n);
    vector<bool> visited(n,false);
    vector<int> adj;
    for(auto& e:edges)
    {
        graph[e[0]].push_back(e[1]);
        graph[e[1]].push_back(e[0]);
    }
    visited[0]=true;
    for(auto& a: graph[0])
    {
        adj.push_back(a);
    }
    dfs(1,0,visited,adj,info,graph);
    return answer;
}