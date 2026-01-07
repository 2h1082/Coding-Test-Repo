#include<bits/stdc++.h>
using namespace std;

int Dx[4]={0,0,-1,1};
int Dy[4]={-1,1,0,0};
int solution(vector<vector<int> > Maps)
{
    int Ans = 0;
    int N=Maps.size(), M=Maps[0].size();
    vector<vector<int>> Used(N,vector<int>(M,0));
    queue<pair<int,int>> Q;
    Q.push({0,0});
    Used[0][0]=1;
    
    while(!Q.empty())
    {
        auto [x, y] = Q.front();
        Q.pop();
        if(x==M-1 && y==N-1) return Used[y][x];
        for(int i=0;i<4;++i)
        {
            int Nx=x+Dx[i], Ny=y+Dy[i];
            if(Nx<0 || Nx>=M || Ny<0 || Ny>=N) continue;
            if(Used[Ny][Nx] || !Maps[Ny][Nx])  continue;
            
            Q.push({Nx,Ny});
            Used[Ny][Nx]=Used[y][x]+1;
        }
    }
    
    return -1;
}