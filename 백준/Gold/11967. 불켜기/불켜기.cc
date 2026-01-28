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
    
    int Cnt=1;
    vector<vector<int>> Map(N,vector<int>(N,0));
    vector<vector<bool>> Used(N,vector<bool>(N,false));
    vector<vector<vector<pair<int,int>>>> Switch(N,vector<vector<pair<int,int>>>(N));
    Map[0][0]=1;
    Used[0][0]=true;
    while(M--)
    {
        int x, y, a, b;
        cin>>x>>y>>a>>b;
        Switch[y-1][x-1].push_back({b-1,a-1});
    }
    
    queue<pair<int,int>> Q;
    Q.push({0,0});
    while(!Q.empty())
    {
        auto [Cy,Cx]=Q.front();
        Q.pop();
        for(auto [Ny, Nx]:Switch[Cy][Cx])
        {
            if(Map[Ny][Nx]) continue;
            // 1. 현재 방에서 킬 수 있는 불을 모두 킨다
            Map[Ny][Nx]=1;
            ++Cnt;
            // 2. 불이 켜진 방 중에 방문 가능한 곳이 있다면 큐에 추가
            // - 불이 켜진 방에 인접한 방들 중에 방문했던 곳이 있다면 방문 가능
            for(int i=0;i<4;++i)
            {
                int Py=Ny+dy[i], Px=Nx+dx[i];
                if(Py<0 || Py>=N || Px<0 || Px>=N || !Used[Py][Px]) continue;
                Used[Ny][Nx]=true;
                Q.push({Ny,Nx});
                break;
            }
        }
        for(int i=0;i<4;++i)
        {
            int Ny=Cy+dy[i], Nx=Cx+dx[i];
            if(Ny<0 || Ny>=N || Nx<0 || Nx>=N || !Map[Ny][Nx] || Used[Ny][Nx]) continue;
            Used[Ny][Nx]=true;
            Q.push({Ny,Nx});
        }
    }
    cout<<Cnt;
}