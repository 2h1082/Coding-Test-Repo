#include <bits/stdc++.h>
using namespace std;

unordered_map<string,vector<pair<string,bool>>> Graph;
int N=0;
vector<string> Res;
bool DFS(string Cur, vector<string>& Ans)
{
    if(Ans.size()==N+1)
    {
        Res=Ans;
        return true;
    }
    
    // 그래프 탐색
    for(auto& [Nxt,bIsUsed] : Graph[Cur])
    {
        if(bIsUsed) continue;
        
        bIsUsed=true;
        Ans.push_back(Nxt);
        if(DFS(Nxt,Ans)) return true;
        Ans.pop_back();
        bIsUsed=false;
    }
    return false;
}
vector<string> solution(vector<vector<string>> Tickets) 
{
    vector<string> Ans(1,"ICN");
    
    // 티켓 알파벳 순 정렬
    sort(Tickets.begin(),Tickets.end());
    N=Tickets.size();
    
    // 그래프 구성
    for(auto& Cur : Tickets)
    {
        Graph[Cur[0]].push_back({Cur[1],false});
    }
    
    // DFS
    DFS("ICN",Ans);
    
    return Res;
}