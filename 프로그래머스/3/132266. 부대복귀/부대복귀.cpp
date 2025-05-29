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
    
    for(auto& s:sources)
    {
        queue<pair<int,int>> q;
        vector<bool> v(n+1,false);
        q.push({s,0});
        v[s]=true;
        bool find=false;
        while(!q.empty())
        {
            auto [cur,count]=q.front();
            q.pop();
            if(destination==cur)
            {
                answer.push_back(count);
                find=true;
            }
            for(auto& next:graph[cur])
            {
                if(!v[next])
                {
                    v[next]=true;
                    q.push({next,count+1});
                }
            }
        }
        if(!find) answer.push_back(-1);
    }
    return answer;
}