#include "bits/stdc++.h"
using namespace std;

int N,M;
vector<string> A;
bool IsInRange(int y, int x)
{
    return y>=0 && y<N && x>=0 && x<M;
}
int Fall(int y, int x, int g)
{
    int dy=(g==0 ? 1 : -1);
    while(1)
    {
        if(A[y][x]=='D')     return -2;
        int ny=y+dy;
        if(!IsInRange(ny,x)) return -1;
        if(A[ny][x]=='#')    return y;
        y=ny;
    }
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    cin>>N>>M;
    
    A.resize(N);
    deque<tuple<int,int,int,int>> q;
    vector<vector<vector<int>>> Dist(N,vector<vector<int>>(M,vector<int>(2,1e9)));
    int sx=-1, sy=-1;
    for(int i=0;i<N;++i) 
    {
        cin>>A[i];
        for(int j=0;j<M;++j)
        {
            if(A[i][j]=='C') 
            {
                sx=j;
                sy=i;
            }
        }
    }
    int fy=Fall(sy,sx,0);
    if(fy==-1)
    {
        cout<<-1;
        return 0;
    }
    else if(fy==-2)
    {
        cout<<0;
        return 0;
    }
    
    Dist[fy][sx][0]=0;
    q.push_back({fy,sx,0,0});
    
    int Ans=1e9;
    while(!q.empty())
    {
        auto [y,x,g,Cost]=q.front();
        q.pop_front();
        
        if(Dist[y][x][g] < Cost) continue;
        
        for(int dx : {-1, 1})
        {
            int nx=x+dx;
            if(!IsInRange(y,nx) || A[y][nx]=='#') continue;;

            int ny=Fall(y,nx,g);
            if(ny==-1)
            {
                continue;
            }
            else if(ny==-2)
            {
                Ans=min(Ans,Cost);
                continue;
            }

            if(Dist[ny][nx][g] > Cost)
            {
                Dist[ny][nx][g]=Dist[y][x][g];
                q.push_front({ny,nx,g,Cost});
            }
        }
        int ng=g^1;
        int ny=Fall(y,x,ng);
        if(ny==-1)
        {
            continue;
        }
        else if(ny==-2)
        {
            Ans=min(Ans,Cost+1);
            continue;
        }

        if(Dist[ny][x][ng] > Cost+1)
        {
            Dist[ny][x][ng]=Cost+1;
            q.push_back({ny,x,ng,Cost+1});
        }
    }
    cout<<(Ans==1e9 ? -1 : Ans);
}