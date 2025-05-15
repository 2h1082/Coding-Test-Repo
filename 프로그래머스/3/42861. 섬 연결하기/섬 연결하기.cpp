#include <bits/stdc++.h>

using namespace std;

int solution(int n, vector<vector<int>> costs) {
    int answer = 0;
    vector<vector<pair<int,int>>> path(n);
    for(auto& cost:costs)
    {
        path[cost[0]].push_back({cost[1],cost[2]});
        path[cost[1]].push_back({cost[0],cost[2]});
    }
    vector<bool> visited(n,false);
    priority_queue<pair<int,int>,vector<pair<int,int>>,greater<>> pq;
    
    pq.push({0,0});
    while(!pq.empty())
    {
        auto [cost,cur]=pq.top();
        pq.pop();
        
        if(visited[cur]) continue;
        visited[cur]=true;
        answer+=cost;
        for(auto& [next,ncost]:path[cur])
        {
            if(!visited[next])
            {
                pq.push({ncost,next});
            }
        }
    }
    return answer;
}