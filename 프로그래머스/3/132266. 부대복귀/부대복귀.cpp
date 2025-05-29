#include <bits/stdc++.h>

using namespace std;

vector<int> solution(int n, vector<vector<int>> roads, vector<int> sources, int destination) {
    vector<int> answer;
    vector<vector<int>> graph(n+1,vector<int>());
    for(auto& r:roads)
    {
        graph[r[0]].push_back(r[1]);
        graph[r[1]].push_back(r[0]);
    }
    vector<int> dist(n+1,INT_MAX);
    queue<int> q;
    dist[destination]=0;
    q.push(destination);
    while(!q.empty())
    {
        int cur=q.front();
        q.pop();
        for(int next:graph[cur])
        {
           if(dist[next]==INT_MAX)
           {
               dist[next]=dist[cur]+1;
               q.push(next);
           }
        }
    }
    for(int s:sources)
    {
        answer.push_back(dist[s]==INT_MAX?-1:dist[s]);
    }
    return answer;
}