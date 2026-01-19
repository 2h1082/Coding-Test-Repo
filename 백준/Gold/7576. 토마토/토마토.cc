#include "bits/stdc++.h"
using namespace std;

int dy[]={-1,1,0,0};
int dx[]={0,0,-1,1};
vector<vector<int>> Map, Used;
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    
    int N,M;
    cin>>M>>N;
    Map.assign(N,vector<int>(M,0));
    Used.assign(N,vector<int>(M,0));
    
    queue<pair<int,int>> Q;
    int Green=0, Max=0;
    for(int i=0;i<N;++i)
    {
        for(int j=0;j<M;++j) 
        {
            cin>>Map[i][j];
            if(Map[i][j]==1) 
            {
                Q.push({i,j});
                Used[i][j]=1;
            }
            else if(!Map[i][j]) ++Green;
        }
    }
    if(!Green)
    {
        cout<<0;
        return 0;
    }
    
    while(!Q.empty())
    {
        auto [Cy,Cx]=Q.front();
        Q.pop();
        for(int i=0;i<4;++i)
        {
            int Ny=Cy+dy[i], Nx=Cx+dx[i];
            if(Ny<0 || Ny>=N || Nx<0 || Nx>=M || Used[Ny][Nx] || Map[Ny][Nx]) continue;
            Q.push({Ny,Nx});
            Used[Ny][Nx]=Used[Cy][Cx]+1;
            Max=max(Max,Used[Ny][Nx]);
            --Green;
        }
    }
    if(Green) cout<<-1;
    else      cout<<Max-1;
}