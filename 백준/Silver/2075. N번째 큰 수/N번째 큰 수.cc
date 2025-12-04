#include "bits/stdc++.h"
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    int N;
    cin>>N;
    
    vector<vector<int>> B(N,vector<int>(N,0));
    priority_queue<int, vector<int>, greater<>> pq;
    for(auto& r : B)
    {
        for(auto& c : r)
        {
            cin>>c;
            pq.push(c);
            if(pq.size()>N) pq.pop();
        }
    }
    cout<<pq.top();
}
