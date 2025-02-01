#include <string>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

int solution(vector<int> priorities, int location) {
    int answer = 1;
    queue<int> q;
    for(int i=0;i<priorities.size();++i)
    {
        q.push(i);
    }
    auto Max=max_element(priorities.begin(),priorities.end());
    while(!q.empty())
    {
        if(*Max==priorities[q.front()])
        {
            if(location==q.front())
            {
                break;
            }
            priorities[q.front()]=0;
            Max=max_element(priorities.begin(),priorities.end());
            ++answer;
        }
        else
        {
            q.push(q.front());
        }
        q.pop();
    }
    return answer;
}