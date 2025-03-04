#include <bits/stdc++.h>

using namespace std;

int TimeConvert(string time)
{
    int hour=stoi(time.substr(0,2));
    int minute=stoi(time.substr(3,2));
    return 60*hour+minute;
}

int solution(vector<vector<string>> book_time) {
    int answer = 0;
    vector<pair<int, int>> list;
    for(auto v : book_time)
    {
        int start=TimeConvert(v[0]);
        int end=TimeConvert(v[1])+10;
        list.push_back({start,end});
    }
    sort(list.begin(),list.end());
    
    priority_queue<int, vector<int>, greater<int>> pq;
    for(auto i : list)
    {
        if(!pq.empty()&&pq.top()<=i.first)
        {
            pq.pop();
        }
        pq.push(i.second);
    }
    
    
    return pq.size();
}