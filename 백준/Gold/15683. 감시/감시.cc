#include "bits/stdc++.h"
using namespace std;

int dy[]={-1,1,0,0};
int dx[]={0,0,-1,1};
// 카메라 타입별 가능한 방향 배치 세트
vector<vector<vector<int>>> DirSet={
    {},
    {{0},{1},{2},{3}},
    {{0,1},{2,3}},
    {{0,2},{0,3},{1,2},{1,3}},
    {{0,1,2},{0,1,3},{0,2,3},{1,2,3}},
    {{0,1,2,3}}
};
int Total=0, N, M, Size=0, Max=0;
vector<vector<int>> A;
vector<pair<int,int>> Camera;
int Watch(int Y, int X, int D, vector<pair<int,int>>& Changed)
{
    int Ny=Y, Nx=X, Cnt=0;
    while(1)
    {
        Ny+=dy[D];
        Nx+=dx[D];
        if(Ny<0 || Ny>=N || Nx<0 || Nx>=M || A[Ny][Nx]==6) break;
        if(!A[Ny][Nx])
        {
            ++Cnt;
            Changed.push_back({Ny,Nx});
            A[Ny][Nx]=-1;
        }
    }
    return Cnt;
}
void DFS(int Cur, int Cnt)
{
    if(Cur==Size)
    {
        Max=max(Max,Cnt);
        return;
    }
    auto [Y,X]=Camera[Cur];
    for(auto& Dir : DirSet[A[Y][X]])
    {
        vector<pair<int,int>> Changed;
        int Add=0;
        for(int D : Dir) Add+=Watch(Y,X,D,Changed);
        DFS(Cur+1,Cnt+Add);
        for(auto& [r,c] : Changed) A[r][c]=0;
    }
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    
    cin>>N>>M;
    A.assign(N,vector<int>(M,0));
    Total=N*M;
    for(int i=0;i<N;++i)
    {
        for(int j=0;j<M;++j)
        {
            cin>>A[i][j];
            if(!A[i][j]) continue;
            --Total;
            if(A[i][j]!=6) Camera.push_back({i,j});
        }
    }
    Size=Camera.size();
    DFS(0,0);
    cout<<Total-Max;
}