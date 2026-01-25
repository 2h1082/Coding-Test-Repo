#include "bits/stdc++.h"
using namespace std;

int dy[]={-1,1,0,0};
int dx[]={0,0,-1,1};
int N,M;
vector<vector<int>> Map;
void BFS(int Sy, int Sx, vector<vector<bool>>& Used)
{
    queue<pair<int,int>> Q;
    Q.push({Sy,Sx});
    Used[Sy][Sx]=true;
    while(!Q.empty())
    {
        auto [Cy,Cx]=Q.front();
        Q.pop();
        for(int i=0;i<4;++i)
        {
            int Ny=Cy+dy[i], Nx=Cx+dx[i];
            if(Ny<0 || Ny>=N || Nx<0 || Nx>=M || Used[Ny][Nx] || !Map[Ny][Nx]) continue;
            Q.push({Ny,Nx});
            Used[Ny][Nx]=true;
        }
    }
}
int CountGroup(vector<pair<int,int>>& Cand)
{
    int Cnt=0;
    vector<vector<bool>> Used(N,vector<bool>(M,false));
    for(auto& [Cy,Cx] : Cand)
    {
        if(Used[Cy][Cx] || !Map[Cy][Cx]) continue;
        BFS(Cy,Cx,Used);
        ++Cnt;
    }
    return Cnt;
}
void MeltDown(vector<pair<int,int>>& Cand)
{
    vector<pair<int,int>> NewCand;
    vector<vector<int>> BaseMap=Map;
    for(auto [Cy,Cx] : Cand)
    {
        for(int i=0;i<4;++i)
        {
            int Ny=Cy+dy[i], Nx=Cx+dx[i];
            if(Ny<0 || Ny>=N || Nx<0 || Nx>=M || BaseMap[Ny][Nx]) continue;
            --Map[Cy][Cx];
            if(Map[Cy][Cx]<1) break;
        }
        if(Map[Cy][Cx]>0) NewCand.push_back({Cy,Cx});
    }
    Cand=move(NewCand);
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    
    cin>>N>>M;
    Map.assign(N,vector<int>(M,0));
    vector<pair<int,int>> Cand;
    for(int i=0;i<N;++i)
    {
        for(int j=0;j<M;++j)
        {
            cin>>Map[i][j];
            if(Map[i][j]) Cand.push_back({i,j});
        }
    }
    int Time=0;
    while(1)
    {
        ++Time;
        MeltDown(Cand);
        if(Cand.size()<1)
        {
            cout<<0;
            break;
        }
        int Cnt=CountGroup(Cand);
        if(Cnt>1)
        {
            cout<<Time;
            break;
        }
    }
}