#include "bits/stdc++.h"
using namespace std;

int Cnt=0;
void DFS(int Cur, vector<int>& Used, vector<int>& Graph)
{
    Used[Cur]=1;
    int Nxt=Graph[Cur];
    if(!Used[Nxt]) DFS(Nxt,Used,Graph);
    else if(Used[Nxt]==1) 
    {
        for(int i=Nxt;i!=Cur;i=Graph[i]) 
        {
            if(Used[i]==1) --Cnt;
        }
        --Cnt;
    }
    Used[Cur]=2;
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    
    int T;
    cin>>T;
    while(T--)
    {
        int N;
        cin>>N;
        
        Cnt=N;
        vector<int> Graph(N+1,0);
        vector<int> Used(N+1,0);  // 0 : 미방문, 1 : 현재 경로에서 방문, 2 : 이미 방문
        for(int i=1;i<=N;++i) cin>>Graph[i];
        
        for(int i=1;i<=N;++i)
        {
            if(Used[i]) continue;
            DFS(i,Used,Graph);
        }
        cout<<Cnt<<'\n';
    }
}