#include "bits/stdc++.h"
using namespace std;

int Dist[1001][1001][11][2];
int dy[]={-1,1,0,0};
int dx[]={0,0,-1,1};
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    
    int N,M,K;
    cin>>N>>M>>K;
    
    vector<string> Map(N);
    for(auto& r : Map) cin>>r;
    
    queue<tuple<int,int,int,int>> Q;
    Q.push({0,0,K,0});
    Dist[0][0][K][0]=1;
    int Ans=-1;
    while(!Q.empty())
    {
        auto [Cy,Cx,Cnt,bIsNight]=Q.front();
        Q.pop();
        if(Cy==N-1 && Cx==M-1)
        {
            Ans=Dist[Cy][Cx][Cnt][bIsNight];
            break;
        }
        for(int i=0;i<4;++i)
        {
            int Ny=Cy+dy[i], Nx=Cx+dx[i], NxtCnt=Cnt, NxtDist=Dist[Cy][Cx][Cnt][bIsNight]+1;
            if(Ny<0 || Ny>=N || Nx<0 || Nx>=M)        continue;
            if(Map[Ny][Nx]=='1')
            {
                if(Cnt<1)    continue;
                if(bIsNight)
                {
                    Ny=Cy;
                    Nx=Cx;
                }
                else
                {
                    --NxtCnt;
                }
            }
            if(Dist[Ny][Nx][NxtCnt][!bIsNight])       continue;
            Dist[Ny][Nx][NxtCnt][!bIsNight]=NxtDist;
            Q.push({Ny,Nx,NxtCnt,!bIsNight});
        }
    }
    cout<<Ans;
}