#include <bits/stdc++.h>

using namespace std;
vector<vector<int>> Friends;
vector<int> Kids;
vector<bool> Visited;
int N,M,K;

int CountGroup(int Cur, int GID, int& KidsCnt)
{
    Visited[Cur]=true;
    int Cnt=Kids[Cur];
    KidsCnt++;
    
    for(auto& Next : Friends[Cur])
    {
        if(Visited[Next]) continue;
        Cnt+=CountGroup(Next,GID,KidsCnt);
    }
    return Cnt;
}
int main()
{
    
    cin>>N>>M>>K;
    Kids.assign(N+1,0);
    for(int i=1;i<=N;++i)
    {
        cin>>Kids[i];
    }
    Friends.resize(N+1);
    while(M--)
    {
        int a,b;
        cin>>a>>b;
        Friends[a].push_back(b);
        Friends[b].push_back(a);
    }
    int GID=0;
    Visited.assign(N+1,false);
    vector<int> GroupCandy;
    vector<int> KidsCnt;
    for(int i=1;i<=N;++i)
    {
        if(!Visited[i])
        {
            KidsCnt.push_back(0);
            GroupCandy.push_back(0);
            GroupCandy[GID]+=CountGroup(i,GID,KidsCnt[GID]);
            GID++;
        }
    }
    vector<int> DP(K,0);
    
    for(int i=0;i<GroupCandy.size();++i)
    {
        for(int j=K-1;j>=KidsCnt[i];--j)
        {
            DP[j]=max(DP[j],DP[j-KidsCnt[i]]+GroupCandy[i]);
        }
    }
    cout<<DP[K-1];
}