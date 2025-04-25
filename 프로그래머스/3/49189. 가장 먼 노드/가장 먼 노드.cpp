#include <bits/stdc++.h>

using namespace std;

int solution(int n, vector<vector<int>> edge) {
    int answer = 0;
    vector<vector<int>> adj(n+1,vector<int>());
    vector<int> dist(n+1,INT_MAX);
    vector<bool> visited(n+1,false);
    int Max=INT_MIN;
    queue<pair<int,int>> q;
    q.push({1,0});
    for(auto e:edge)
    {
        adj[e[0]].push_back(e[1]);
        adj[e[1]].push_back(e[0]);
    }
    while(!q.empty())
    {
        int cur=q.front().first;
        int dis=q.front().second;
        q.pop();
        
        dist[cur]=min(dist[cur],dis);
        if(Max<dis) Max=dis;
        
        for(int i=0;i<adj[cur].size();i++)
        {
            int next=adj[cur][i];
            if(!visited[next])
            {
                visited[next]=true;
                q.push({next,dis+1});
            }
        }
    }
    answer=count(dist.begin()+1,dist.end(),Max);
    
    return answer;
}