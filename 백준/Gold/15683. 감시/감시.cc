#include "bits/stdc++.h"
using namespace std;

int dx[4]={0,-1,0,1};
int dy[4]={-1,0,1,0};
vector<vector<vector<int>>> Dirs={
    {},
    {{0},{1},{2},{3}},
    {{0,2},{1,3}},
    {{0,1},{1,2},{2,3},{3,0}},
    {{0,1,2},{1,2,3},{2,3,0},{3,0,1}},
    {{0,1,2,3}}
};
vector<pair<int,int>> Camera;
vector<vector<int>> Map;
int Max=0;
int N,M;

int Watch(int y, int x, int Dir, vector<pair<int,int>>& Changed)
{
    int ny=y, nx=x, Cnt=0;
    while(1)
    {
        ny+=dy[Dir];
        nx+=dx[Dir];
        if(ny<0 || ny>=N || nx<0 || nx>=M) break;
        if(Map[ny][nx]==6)                 break;
        
        if(!Map[ny][nx])
        {
            ++Cnt;
            Map[ny][nx]=-1;
            Changed.push_back({ny,nx});
        }
    }
    return Cnt;
}
void DFS(int Idx, int Cnt)
{
    if(Idx==Camera.size())
    {
        Max=max(Max,Cnt);
        return;
    }
    auto [y,x]=Camera[Idx];
    int Type=Map[y][x];
    for(auto& DirSet : Dirs[Type])
    {
        vector<pair<int,int>> Changed;
        int Add=0;
        for(int D : DirSet) Add+=Watch(y,x,D,Changed);
        
        DFS(Idx+1,Cnt+Add);
        
        for(auto [r,c] : Changed) Map[r][c]=0;
    }
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    cin>>N>>M;
    
    Map.assign(N,vector<int>(M,0));
    
    int Total=N*M;
    for(int i=0;i<N;++i)
    {
        for(int j=0;j<M;++j)
        {
            cin>>Map[i][j];
            if(Map[i][j]) 
            {
                --Total;
                if(Map[i][j]!=6) Camera.push_back({i,j});
            }
        }
    }
    DFS(0,0);
    
    cout<<Total-Max;
}