#include "bits/stdc++.h"
using namespace std;

int N;
vector<vector<int>> Map;
int dy[]={-1,1,0,0};
int dx[]={0,0,-1,1};
void BFS(int Sy, int Sx, int H, vector<vector<bool>>& Used)
{
    Used[Sy][Sx]=true;
    queue<pair<int,int>> Q;
    Q.push({Sy,Sx});
    while(!Q.empty())
    {
        auto [Cy,Cx]=Q.front();
        Q.pop();
        for(int i=0;i<4;++i)
        {
            int Ny=Cy+dy[i], Nx=Cx+dx[i];
            if(Ny<0 || Ny>=N || Nx<0 || Nx>=N || Used[Ny][Nx] || Map[Ny][Nx]<=H) continue;
            Q.push({Ny,Nx});
            Used[Ny][Nx]=true;
        }
    }
}
int Count(int H)
{
    vector<vector<bool>> Used(N,vector<bool>(N,false));
    int Cnt=0;
    for(int i=0;i<N;++i)
    {
        for(int j=0;j<N;++j)
        {
            if(Used[i][j] || Map[i][j]<=H) continue;
            BFS(i,j,H,Used);
            ++Cnt;
        }
    }
    return Cnt;
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    
    cin>>N;
    Map.assign(N,vector<int>(N,0));
    int MaxH=0, Max=1;
    for(auto& r : Map)
    {
        for(auto& c : r)
        {
            cin>>c;
            MaxH=max(MaxH,c);
        }
    }
    for(int i=1;i<MaxH;++i)
    {
        int Cnt=Count(i);
        Max=max(Max,Cnt);
    }
    cout<<Max;
}