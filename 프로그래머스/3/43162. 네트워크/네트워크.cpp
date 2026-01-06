#include <bits/stdc++.h>
using namespace std;

vector<bool> Used;
void DFS(int Cur, const vector<vector<int>>& Computers, const int& N)
{
    Used[Cur]=true;
    for(int i=0;i<N;++i)
    {
        if(Used[i] || !Computers[Cur][i]) continue;
        
        DFS(i,Computers,N);
    }
}
int solution(int N, vector<vector<int>> Computers) 
{
    int Ans = 0;
    Used.assign(N,false);
    
    for(int i=0;i<N;++i)
    {
        if(Used[i]) continue;
        DFS(i,Computers,N);
        Ans++;
    }
    return Ans;
}