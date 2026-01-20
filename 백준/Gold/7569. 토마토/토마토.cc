#include "bits/stdc++.h"
using namespace std;

int dx[]={0,0,-1,1,0,0};
int dy[]={-1,1,0,0,0,0};
int dz[]={0,0,0,0,-1,1};
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    
    int M,N,H, Green=0;
    cin>>M>>N>>H;
    vector<vector<vector<int>>> Box(H,vector<vector<int>>(N,vector<int>(M,0))), Dist(H,vector<vector<int>>(N,vector<int>(M,-1)));
    queue<tuple<int,int,int>> Q;
    for(int h=0;h<H;++h)
    {
        for(int i=0;i<N;++i)
        {
            for(int j=0;j<M;++j)
            {
                cin>>Box[h][i][j];
                if(!Box[h][i][j])        ++Green;
                else if(Box[h][i][j]==1) 
                {
                    Q.push({h,i,j});
                    Dist[h][i][j]=0;
                }
            }
        }
    }
    
    int Max=0;
    if(!Green)
    {
        cout<<0;
        return 0;
    }
    while(!Q.empty())
    {
        auto [Cz,Cy,Cx]=Q.front();
        Q.pop();
        for(int i=0;i<6;++i)
        {
            int Nz=Cz+dz[i], Ny=Cy+dy[i], Nx=Cx+dx[i];
            if(Nz<0 || Nz>=H || Ny<0 || Ny>=N || Nx<0 || Nx>=M || Box[Nz][Ny][Nx] || Dist[Nz][Ny][Nx]!=-1) continue;
            Dist[Nz][Ny][Nx]=Dist[Cz][Cy][Cx]+1;
            Max=max(Max,Dist[Nz][Ny][Nx]);
            Q.push({Nz,Ny,Nx});
            --Green;
        }
    }
    if(Green) cout<<-1;
    else      cout<<Max;
}