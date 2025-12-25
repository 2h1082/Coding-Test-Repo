#include "bits/stdc++.h"

using namespace std;

int solution(vector<int> Scoville, int K) {
    int Ans=0;
    priority_queue<int,vector<int>,greater<>> pq;
    for(auto& s : Scoville) pq.push(s);
    
    int Prev=0;
    while(!pq.empty())
    {
        int Cur=pq.top();
        pq.pop();
        if(Cur >= K) break;
        if(Cur < K)
        {
            if(pq.empty()) 
            {
                Ans=-1;
                break;
            }
            int Nxt=pq.top();
            pq.pop();
            Nxt= Nxt*2 + Cur;
            pq.push(Nxt);
            Ans++;
        }
    }
    
    return Ans;
}