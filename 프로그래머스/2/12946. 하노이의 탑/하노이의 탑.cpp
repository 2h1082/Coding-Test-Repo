#include <bits/stdc++.h>
using namespace std;

void Hanoi(int n, int start, int middle, int target, vector<vector<int>>& answer)
{
    if(n==1)
    {
        answer.push_back({start,target});
        return;
    }
    Hanoi(n-1,start,target,middle,answer);
    answer.push_back({start,target});
    Hanoi(n-1,middle,start,target,answer);
    
}

vector<vector<int>> solution(int n) {
    vector<vector<int>> answer;
    Hanoi(n,1,2,3,answer);
    
    return answer;
}