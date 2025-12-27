#include "bits/stdc++.h"
using namespace std;

int dx[]={0,0,-1,1};
int dy[]={-1,1,0,0};
int solution(vector<vector<int>> Rectangle, int Sx, int Sy, int Ix, int Iy) {
    int Ans = 0;
    vector<vector<int>> Map(101, vector<int>(101,0)), Dist(101, vector<int>(101,-1));
    for(auto& R : Rectangle)
    {
        int LowX= R[0]*2, LowY=R[1]*2, UpX=R[2]*2, UpY=R[3]*2;
        for(int i=LowY;i<=UpY;++i)
        {
            for(int j=LowX;j<=UpX;++j)
            {
                if(Map[i][j]==-1) continue;
                
                if(i==LowY || i==UpY || j==LowX || j==UpX) Map[i][j]=1;
                else                                       Map[i][j]=-1;
            }
        }
    }
    
    queue<pair<int,int>> q;
    q.push({Sy*2,Sx*2});
    Dist[Sy*2][Sx*2]=0;
    
    while(!q.empty())
    {
        auto [Cy, Cx]=q.front();
        q.pop();
        if(Cy==Iy*2 && Cx==Ix*2) return Dist[Cy][Cx]/2;
        
        for(int i=0;i<4;++i)
        {
            int Ny=Cy+dy[i], Nx=Cx+dx[i];
            if(Ny<0 || Ny>100 || Nx<0 || Nx>100) continue;
            if(Map[Ny][Nx]!=1 || Dist[Ny][Nx]!=-1)  continue;
            
            q.push({Ny,Nx});
            Dist[Ny][Nx]=Dist[Cy][Cx]+1;
        }
    }
    return Ans;
}