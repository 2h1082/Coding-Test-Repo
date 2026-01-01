#include "bits/stdc++.h"
using namespace std;

int Max=0, N=0;
vector<bool> Used;
void DFS(int Cnt, int Remain, vector<vector<int>>& D)
{
    Max=max(Max,Cnt);
    
    for(int i=0;i<N;++i)
    {
        int MinStamina=D[i][0], Cost=D[i][1];
        if(Used[i] || MinStamina > Remain || Remain < Cost) continue;
        
        Used[i]=true;
        DFS(Cnt+1,Remain-Cost,D);
        Used[i]=false;
    }
}
int solution(int k, vector<vector<int>> Dungeons) 
{
    N=Dungeons.size();
    Used.assign(N,false);
    DFS(0,k,Dungeons);
    
    return Max;
}