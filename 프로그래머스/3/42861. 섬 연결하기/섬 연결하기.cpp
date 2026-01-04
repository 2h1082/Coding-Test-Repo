#include <bits/stdc++.h>
using namespace std;

int solution(int N, vector<vector<int>> Costs) 
{
    int Ans = 0;
    // 그래프 구성
    vector<vector<pair<int,int>>> Graph(N);
    for(auto& Info : Costs)
    {
        int U=Info[0], V=Info[1], W=Info[2];
        Graph[U].push_back({V,W});
        Graph[V].push_back({U,W});
    }
    
    // 프림 알고리즘
    priority_queue<pair<int,int>,vector<pair<int,int>>, greater<>> Q;
    Q.push({0,0});
    int Cnt=0;
    vector<bool> Used(N,false);
    while(!Q.empty() && Cnt < N-1)
    {
        auto [W, Cur]=Q.top();
        Q.pop();
        if(Used[Cur]) continue;
        
        Ans+=W;
        Used[Cur]=true;
        for(auto& [Nxt, Cost] : Graph[Cur])
        {
            if(Used[Nxt]) continue;
            
            Q.push({Cost,Nxt});
        }
    }
    
    return Ans;
}