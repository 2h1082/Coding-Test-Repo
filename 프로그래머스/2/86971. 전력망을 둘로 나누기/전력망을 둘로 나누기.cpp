#include <bits/stdc++.h>

using namespace std;

vector<vector<int>> graph;
vector<bool> visited;

int CountNodes(int node)
{
    visited[node]=true;
    int count=1;
    
    for(int NextNode: graph[node])
    {
        if(!visited[NextNode])
        {
            count+=CountNodes(NextNode);
        }
    }
    return count;
}

int solution(int n, vector<vector<int>> wires) {
    int answer = n;
    
    graph.assign(n+1,vector<int>());
    
    for(vector<int> v : wires)
    {
        //간선 연결
        graph[v[0]].push_back(v[1]);
        graph[v[1]].push_back(v[0]);
    }
    
    for(vector<int> v : wires)
    {
        //간선 삭제
        graph[v[0]].erase(remove(graph[v[0]].begin(),graph[v[0]].end(),v[1]),graph[v[0]].end());
        graph[v[1]].erase(remove(graph[v[1]].begin(),graph[v[1]].end(),v[0]),graph[v[1]].end());
        
        //DFS로 한쪽 트리 노드 개수 구하기
        visited.assign(n+1,false);
        int NodeCount=CountNodes(v[0]);
        int Abs=abs((n-NodeCount)-NodeCount);
        answer=min(Abs,answer);
        
        //간선 다시 연결
        graph[v[0]].push_back(v[1]);
        graph[v[1]].push_back(v[0]);
    }
    
    
    return answer;
}
