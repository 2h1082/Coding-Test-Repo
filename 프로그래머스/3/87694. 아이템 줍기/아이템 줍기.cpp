#include "bits/stdc++.h"
using namespace std;

int Dx[]={0,0,-1,1};
int Dy[]={-1,1,0,0};
int solution(vector<vector<int>> Rectangle, int Sx, int Sy, int Ix, int Iy) 
{
    vector<vector<int>> Used(101,vector<int>(101,0)), Map(101,vector<int>(101,0));
    
    // 주어진 직사각형 테두리 기준 이용 가능 경로 맵 구성
    for(auto Rect : Rectangle)
    {
        int LeftX=Rect[0]*2, DownY=Rect[1]*2, RightX=Rect[2]*2, UpY=Rect[3]*2;
        for(int i=DownY;i<=UpY;++i)
        {
            for(int j=LeftX;j<=RightX;++j)
            {
                if(Map[i][j]==-1)                                continue;     // 다른 사각형의 내부 (건너뜀)
                if(i==DownY || i==UpY || j==LeftX || j==RightX)  Map[i][j]=1;  // 내부에 포함되지 않는 테두리 
                else                                             Map[i][j]=-1; // 사각형 내부는 따로 -1로 처리
            }
        }
    }
    
    queue<pair<int,int>> Q;
    Used[Sy*2][Sx*2]=1;
    Q.push({Sy*2, Sx*2});
    while(!Q.empty())
    {
        auto [y, x] = Q.front();
        Q.pop();
        if(y==Iy*2 && x==Ix*2) return Used[y][x]/2;
        
        for(int i=0;i<4;++i)
        {
            int Ny=y+Dy[i], Nx=x+Dx[i];
            if(Ny<0 || Ny>100 || Nx<0 || Nx>100) continue;
            if(Used[Ny][Nx] || Map[Ny][Nx]!=1)   continue;
            
            Q.push({Ny,Nx});
            Used[Ny][Nx]=Used[y][x]+1;
        }
    }
    return -1;
}