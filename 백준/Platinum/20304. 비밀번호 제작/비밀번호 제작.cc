#include "bits/stdc++.h"
using namespace std;

int dy[]={-1,1,0,0};
int dx[]={0,0,-1,1};
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    
    int N,M;
    cin>>N>>M;
    
    vector<int> Dist(N+1,-1);
    queue<int> Q;
    while(M--)
    {
        int T;
        cin>>T;
        Dist[T]=0;
        Q.push(T);
    }
    int Max=0;
    while(!Q.empty())
    {
        int Cur=Q.front();
        Q.pop();
        Max=max(Max,Dist[Cur]);
        for(int i=0;i<20;++i)
        {
            int Nxt=Cur^(1<<i);
            if(Nxt>N || Dist[Nxt]!=-1) continue;
            Dist[Nxt]=Dist[Cur]+1;
            Q.push(Nxt);
        }
    }
    cout<<Max;
}
