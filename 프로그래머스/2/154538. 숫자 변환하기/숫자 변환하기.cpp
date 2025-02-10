#include <string>
#include <vector>
#include <queue>
#include <unordered_set>

using namespace std;

int solution(int x, int y, int n) {
    if (x==y) return 0;
    
    queue<pair<int, int>> q;
    unordered_set<int> visited;
    q.push({y,0});
    visited.insert(y);
    while(!q.empty())
    {
        int cur=q.front().first;
        int count=q.front().second;
        q.pop();
        if(cur==x) return count;
        if(cur-n>=x&&visited.find(cur-n)==visited.end())
        {
            q.push({cur-n,count+1});
            visited.insert(cur-n);
        }
        if(cur%2==0&&visited.find(cur/2)==visited.end())
        {
            q.push({cur/2,count+1});
            visited.insert(cur/2);
        }
        if(cur%3==0&&visited.find(cur/3)==visited.end())
        {
            q.push({cur/3,count+1});
            visited.insert(cur/3);
        }
    }
    return -1;
}