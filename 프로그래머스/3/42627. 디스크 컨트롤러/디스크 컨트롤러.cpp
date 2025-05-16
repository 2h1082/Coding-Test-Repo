#include <bits/stdc++.h>

using namespace std;

int solution(vector<vector<int>> jobs) {
    int answer = 0;
    int n=jobs.size();
    priority_queue<vector<int>, vector<vector<int>>, greater<>> pq;
    for(int i=0;i<n;i++)
    {
        jobs[i].push_back(i);
    }
    sort(jobs.begin(),jobs.end());
    int time=jobs[0][0];
    int next=1;
    pq.push({jobs[0][1],jobs[0][0],jobs[0][2]});
    while(next<n||!pq.empty())
    {
        while((next<n)&&(time>=jobs[next][0])) 
        {
            pq.push({jobs[next][1],jobs[next][0],jobs[next][2]});
            next++;
        }
        if(pq.empty())
        {
            time=jobs[next][0];
            pq.push({jobs[next][1],jobs[next][0],jobs[next][2]});
            next++;
        }
        
        auto v=pq.top(); //0:len, 1:start time, 2:index
        pq.pop();
        time+=v[0];
        answer+=time-v[1];
    }
    
    return answer/n;
}