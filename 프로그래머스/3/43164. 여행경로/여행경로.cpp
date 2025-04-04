#include <bits/stdc++.h>

using namespace std;


vector<string> solution(vector<vector<string>> tickets) {
    vector<string> answer;
    unordered_map<string, multiset<string>> graph;
    for(auto ticket:tickets)
    {
        graph[ticket[0]].insert(ticket[1]);
    }
    function<void(string)> DFS=[&](string t)
    {
        while(!graph[t].empty())
        {
            string n=*graph[t].begin();
            graph[t].erase(graph[t].begin());
            DFS(n);
        }
        answer.push_back(t);
    };
    DFS("ICN");
    reverse(answer.begin(),answer.end());
    return answer;
}