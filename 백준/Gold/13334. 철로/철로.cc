#include <bits/stdc++.h>

using namespace std;

int main()
{
    int N=0, d=0;
    cin>>N;
    
    vector<pair<int,int>> P(N);
    for(auto& [p1,p2] : P)
    {
        cin>>p1>>p2;
        if(p1>p2) swap(p1,p2);
    }
    cin>>d;
    sort(P.begin(),P.end(),[](const auto& v1, const auto& v2){
        return v1.second<v2.second;
    });
    int answer=0;
    priority_queue<int,vector<int>,greater<>> pq;
    for(auto& [s,e] : P)
    {
        if(s<e-d) continue;
        
        pq.push(s);
        while(!pq.empty()&&pq.top()<e-d)
        {
            pq.pop();
        }
        answer=max((int)pq.size(),answer);
    }
    cout<<answer;
}