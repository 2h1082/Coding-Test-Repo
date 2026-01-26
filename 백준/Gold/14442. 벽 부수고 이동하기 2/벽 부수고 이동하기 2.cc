#include "bits/stdc++.h"
using namespace std;

int dy[]={-1,1,0,0};
int dx[]={0,0,-1,1};
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    
    int N,M,K;
    cin>>N>>M>>K;
    
    vector<string> Map(N);
    vector<vector<vector<int>>> Dist(N,vector<vector<int>>(M,vector<int>(K+1,1e9)));
    for(auto& r : Map)
    {
        cin>>r;
    }
    
    queue<tuple<int,int,int>> Q; // y,x,WallBreakChance
    Q.push({0,0,K});
    Dist[0][0][K]=1;
    int Ans=1e9;
    while(!Q.empty())
    {
        auto [Cy,Cx,Cnt]=Q.front();
        Q.pop();
        if(Cy==N-1 && Cx==M-1)
        {
            Ans=Dist[Cy][Cx][Cnt];
            break;
        }
        for(int i=0;i<4;++i)
        {
            int Ny=Cy+dy[i], Nx=Cx+dx[i], NxtCnt=Cnt;
            if(Ny<0 || Ny>=N || Nx<0 || Nx>=M) continue;
            if(Map[Ny][Nx]=='1')
            {
                if(Cnt<1) continue;
                --NxtCnt;
            }
            if(Dist[Ny][Nx][NxtCnt]!=1e9) continue;
            
            Dist[Ny][Nx][NxtCnt]=Dist[Cy][Cx][Cnt]+1;
            Q.push({Ny,Nx,NxtCnt});
        }
    }
    
    if(Ans==1e9) cout<<-1;
    else         cout<<Ans;
}