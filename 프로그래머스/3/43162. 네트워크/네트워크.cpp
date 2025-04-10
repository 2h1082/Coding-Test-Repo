#include <bits/stdc++.h>

using namespace std;

int solution(int n, vector<vector<int>> computers) {
    int answer = 0;
    vector<bool> visited(n,false);
    function <void(int)> DFS=[&](int idx){
        visited[idx]=true;
        for(int i=0;i<n;i++)
        {
            if(!visited[i]&&computers[idx][i])
            {
                DFS(i);
            }
        }
    };
    for(int i=0;i<n;i++)
    {
        if(!visited[i])
        {
            DFS(i);
            answer++;
        }
    }
    return answer;
}