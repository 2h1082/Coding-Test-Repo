#include <bits/stdc++.h>
using namespace std;

bool CanConvert(string& S1, string& S2)
{
    int Cnt=0;
    for(int i=0;i<S1.size();++i)
    {
        if(S1[i]!=S2[i]) ++Cnt;
        if(Cnt>1) return false;
    }
    return true;
}
int solution(string Begin, string Target, vector<string> Words) 
{
    queue<pair<string,int>> Q;
    Q.push({Begin,0});
    auto It=find(Words.begin(),Words.end(),Target);
    if(It==Words.end()) return 0;
    
    while(!Q.empty())
    {
        auto [Cur, Cnt]=Q.front();
        Q.pop();
        if(Cur==Target) return Cnt;
        
        for(auto& Nxt : Words)
        {
            if(CanConvert(Cur,Nxt)) Q.push({Nxt,Cnt+1});
        }
    }
    
    return 0;
}