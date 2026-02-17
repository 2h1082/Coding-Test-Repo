#include "bits/stdc++.h"
using namespace std;

int N,M,G,R, Max=0, Size=0;
vector<vector<int>> A;
vector<pair<int,int>> Cand;
int dy[]={-1,1,0,0};
int dx[]={0,0,-1,1};
int BFS(vector<pair<int,int>>& FluidG, vector<pair<int,int>>& FluidR)
{
    int Cnt=0;
    queue<pair<int,int>> Q;
    vector<vector<int>> Used(N,vector<int>(M,1e9)), B=A;
    for(auto [Y,X] : FluidG)
    {
        Q.push({Y,X});
        B[Y][X]=3;
        Used[Y][X]=0;
    }
    for(auto [Y,X] : FluidR)
    {
        Q.push({Y,X});
        B[Y][X]=4;
        Used[Y][X]=0;
    }
    while(!Q.empty())
    {
        auto [Cy,Cx]=Q.front();
        Q.pop();
        if(!B[Cy][Cx]) continue; // 배양액이 만나 꽃이 피어 버린 지점
        for(int d=0;d<4;++d)
        {
            int Ny=Cy+dy[d], Nx=Cx+dx[d];
            if(Ny<0 || Ny>=N || Nx<0 || Nx>=M || !B[Ny][Nx] || B[Ny][Nx]==B[Cy][Cx]) continue;
            int NxtTime=Used[Cy][Cx]+1;
            if(Used[Ny][Nx]==1e9 && (B[Ny][Nx]==1 || B[Ny][Nx]==2)) // 배양액이 퍼질 수 있는 땅
            {
                B[Ny][Nx]=B[Cy][Cx];
                Used[Ny][Nx]=NxtTime;
                Q.push({Ny,Nx});
            }
            else if(NxtTime == Used[Ny][Nx]) // 두 배양액이 동시에 만나는 경우 (꽃이 피는 지점)
            {
                B[Ny][Nx]=0;
                ++Cnt;
            }
        }
    }
    return Cnt;
}
void SelectLoc(int Cur, vector<pair<int,int>>& FluidG, vector<pair<int,int>>& FluidR)
{
    if(Cur==Size)
    {
        if(!G && !R) Max=max(Max,BFS(FluidG,FluidR));
        return;
    }
    SelectLoc(Cur+1,FluidG,FluidR);
    if(G>0)
    {
        --G;
        FluidG.push_back(Cand[Cur]);
        SelectLoc(Cur+1,FluidG,FluidR);
        FluidG.pop_back();
        ++G;
    }
    if(R>0)
    {
        --R;
        FluidR.push_back(Cand[Cur]);
        SelectLoc(Cur+1,FluidG,FluidR);
        FluidR.pop_back();
        ++R;
    }
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    
    cin>>N>>M>>G>>R;
    A.assign(N,vector<int>(M,0));
    for(int i=0;i<N;++i)
    {
        for(int j=0;j<M;++j)
        {
            cin>>A[i][j];
            if(A[i][j]==2) Cand.push_back({i,j});
        }
    }
    Size=Cand.size();
    vector<pair<int,int>> FluidG, FluidR;
    SelectLoc(0,FluidG,FluidR);
    cout<<Max;
}