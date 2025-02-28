#include <bits/stdc++.h>
using namespace std;

int solution(int N, vector<vector<int> > road, int K) {
    int answer = 0;
    vector<vector<pair<int,int>>> graph(N+1);
    vector<int> Path(N+1,INT_MAX);
    priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> pq;
    
    //그래프 구성
    for(auto n:road)
    {
        // 양방향 연결
        graph[n[0]].push_back({n[1],n[2]});
        graph[n[1]].push_back({n[0],n[2]});
    }
    //그래프 탐색(그리디: 다익스트라)
    //1번 노드에서 시작
    Path[1]=0;
    pq.push({0,1}); 
    while(!pq.empty())
    {
        auto [curDist,curNode]=pq.top();
        pq.pop();
        for(auto [nextNode,cost]:graph[curNode])
        {
            int newDist=curDist+cost;
            if(newDist<Path[nextNode])
            {
                Path[nextNode]=newDist;
                pq.push({newDist,nextNode});
            }
        }
    }
    
    for(int i=1;i<N+1;i++)
    {
        if(Path[i]<=K)
        {
            answer++;
        }
    }
    return answer;
}