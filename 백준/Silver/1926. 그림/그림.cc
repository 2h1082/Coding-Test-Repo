#include "bits/stdc++.h"
using namespace std;

int dx[]={0,0,-1,1};
int dy[]={-1,1,0,0};
int N,M;
vector<vector<int>> Map;
vector<vector<bool>> Used;
int BFS(int y, int x)
{
    int Cnt=1;
    queue<pair<int,int>> Q;
    Q.push({y,x});
    Used[y][x]=true;
    while(!Q.empty())
    {
        auto [Cy,Cx]=Q.front();
        Q.pop();
        for(int i=0;i<4;++i)
        {
            int Ny=Cy+dy[i], Nx=Cx+dx[i];
            if(Ny<0 || Ny>=N || Nx<0 || Nx>=M || Used[Ny][Nx] || !Map[Ny][Nx]) continue;
            Used[Ny][Nx]=true;
            Q.push({Ny,Nx});
            ++Cnt;
        }
    }
    return Cnt;
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    
    cin>>N>>M;
    Map.assign(N,vector<int>(M,0));
    Used.assign(N,vector<bool>(M,false));
    for(auto& r : Map)
    {
        for(auto& c : r)
        {
            cin>>c;
        }
    }
    
    int Max=0, Cnt=0;
    for(int i=0;i<N;++i)
    {
        for(int j=0;j<M;++j)
        {
            if(Used[i][j] || !Map[i][j]) continue;
            ++Cnt;
            Max=max(Max,BFS(i,j));
        }
    }
    cout<<Cnt<<'\n'<<Max;
}