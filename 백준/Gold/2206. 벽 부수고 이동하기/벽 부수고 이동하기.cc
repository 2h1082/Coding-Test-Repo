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
    vector<string> Map(N);
    vector<vector<vector<int>>> Dist(N,vector<vector<int>>(M,vector<int>(2,1e9)));
    for(auto& s : Map) cin>>s;
    
    Dist[0][0][0]=Dist[0][0][1]=1;
    queue<tuple<int,int,int>> Q;
    Q.push({0,0,1}); // y, x, Break Opportunity Count
    while(!Q.empty())
    {
        auto [Cy,Cx,Cnt]=Q.front();
        Q.pop();
        for(int i=0;i<4;++i)
        {
            int Ny=Cy+dy[i], Nx=Cx+dx[i], NxtCnt=Cnt;
            if(Ny<0 || Ny>=N || Nx<0 || Nx>=M) continue;
            if(Map[Ny][Nx]=='1' && Cnt>0)
            {
                if(Dist[Ny][Nx][0]!=1e9) continue;
                Dist[Ny][Nx][0]=Dist[Cy][Cx][Cnt]+1;
                Q.push({Ny,Nx,0});
            }
            else if(Map[Ny][Nx]=='0')
            {
                if(Dist[Ny][Nx][Cnt]!=1e9) continue;
                Dist[Ny][Nx][Cnt]=Dist[Cy][Cx][Cnt]+1;
                Q.push({Ny,Nx,Cnt});
            }
        }
    }
    int Ans=min(Dist[N-1][M-1][0],Dist[N-1][M-1][1]);
    if(Ans==1e9) cout<<-1;
    else         cout<<Ans;
}