#include <bits/stdc++.h>
using namespace std;

int solution(vector<vector<int>> Jobs) 
{
    int Ans=0, N=Jobs.size();
    
    sort(Jobs.begin(),Jobs.end());
    priority_queue<pair<int,int>,vector<pair<int,int>>,greater<>> Pq;
    
    int Time=0, Idx=0, Cnt=0;
    while(Cnt < N)
    {
        while(Idx < N && Jobs[Idx][0] <= Time) 
        {
            Pq.push({Jobs[Idx][1],Jobs[Idx][0]});
            Idx++;
        }
        
        if(!Pq.empty())
        {
            auto [Cost, InTime]=Pq.top();
            Pq.pop();
            
            Time+=Cost;
            Ans+=Time-InTime;
            Cnt++;
        }
        else
        {
            Time=Jobs[Idx][0];
        }
    }
    
    return Ans/N;
}