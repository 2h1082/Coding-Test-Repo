#include "bits/stdc++.h"
using namespace std;

int dy[]={-1,1,0,0};
int dx[]={0,0,-1,1};
int N;
vector<vector<int>> Map, IslandId, Dist;
void LabelingIsland(int Sy, int Sx, int Id, queue<tuple<int,int,int>>& CandQ)
{
    queue<pair<int,int>> Q;
    IslandId[Sy][Sx]=Id;
    Q.push({Sy,Sx});
    while(!Q.empty())
    {
        auto [Cy,Cx]=Q.front();
        Q.pop();
        for(int i=0;i<4;++i)
        {
            int Ny=Cy+dy[i], Nx=Cx+dx[i];
            if(Ny<0 || Ny>=N || Nx<0 || Nx>=N || IslandId[Ny][Nx]) continue;
            if(!Map[Ny][Nx]) // 바다에 인접한 해안 블록 (다리 시작점 후보군)
            {
                if(Dist[Ny][Nx]!=1e9) continue;
                CandQ.push({Ny,Nx,Id});
                Dist[Ny][Nx]=1;
            }
            else
            {
                Q.push({Ny,Nx});
            }
            IslandId[Ny][Nx]=Id;
        }
    }
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    
    cin>>N;
    
    Map.assign(N,vector<int>(N,0));
    IslandId.assign(N,vector<int>(N,0));
    Dist.assign(N,vector<int>(N,1e9));
    for(auto& r : Map)
    {
        for(auto& c : r)
        {
            cin>>c;
        }
    }
    int Id=1;
    queue<tuple<int,int,int>> Q; // y, x, Id
    for(int i=0;i<N;++i)
    {
        for(int j=0;j<N;++j)
        {
            if(Map[i][j]==0 || IslandId[i][j]) continue;
            LabelingIsland(i,j,Id,Q);
            ++Id;
        }
    }
    
    int Ans=1e9;
    // 최단 거리 다리 BFS
    while(!Q.empty())
    {
        auto [Cy,Cx,CurId]=Q.front();
        Q.pop();
        if(Dist[Cy][Cx]>=Ans) break;
        for(int i=0;i<4;++i)
        {
            int Ny=Cy+dy[i], Nx=Cx+dx[i];
            if(Ny<0 || Ny>=N || Nx<0 || Nx>=N || IslandId[Ny][Nx]==CurId) continue;
            if(Map[Ny][Nx])
            {
                Ans=min(Ans,Dist[Cy][Cx]);
                continue;
            }
            if(Dist[Ny][Nx]!=1e9)
            {
                Ans=min(Ans,Dist[Ny][Nx]+Dist[Cy][Cx]);
                continue;
            }
            IslandId[Ny][Nx]=CurId;
            Dist[Ny][Nx]=Dist[Cy][Cx]+1;
            Q.push({Ny,Nx,CurId});
        }
    }
    cout<<Ans;
}