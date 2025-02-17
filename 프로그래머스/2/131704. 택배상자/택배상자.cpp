#include <bits/stdc++.h>

using namespace std;

int solution(vector<int> order) {
    int answer = 0;
    stack<int> s;
    queue<int> q(deque(order.begin(),order.end()));
    
    int i=1;
    while(1)
    {
        if(i==q.front())
        {
            q.pop();
            answer++;
        }
        else if(!s.empty()&&s.top()==q.front())
        {
            s.pop();
            q.pop();
            answer++;
            continue;
        }
        else
        {
            s.push(i);
            if(i>order.size()&&i!=q.front()&&s.top()!=q.front()) break;
        }
        i++;
    }
    
    return answer;
}