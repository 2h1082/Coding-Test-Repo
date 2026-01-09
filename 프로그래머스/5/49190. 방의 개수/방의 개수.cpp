#include "bits/stdc++.h"
using namespace std;

int Dx[]={0,1,1,1,0,-1,-1,-1};
int Dy[]={1,1,0,-1,-1,-1,0,1};
int solution(vector<int> Arrows) 
{
    int Ans = 0;
    
    // 노드 및 간선 사용 여부 체크용 컨테이너
    map<pair<int,int>,bool> UsedNode;
    map<tuple<int,int,int,int>,bool> UsedEdge;
    UsedNode[{0,0}]=true;
    int Cx=0, Cy=0;
    for(auto& D : Arrows)
    {
        for(int i=0;i<2;++i) // 좌표 2배 확대하여 사용 (그래야 정확한 방 생성 여부 확인 가능)
        {
            int Ny=Cy+Dy[D], Nx=Cx+Dx[D];
            // 방문했던 좌표인데 현재 이용한 간선은 이용되지 않았다면 방 생성 조건 충족
            if(UsedNode[{Ny,Nx}] && !UsedEdge[{Ny,Nx,Cy,Cx}] && !UsedEdge[{Cy,Cx,Ny,Nx}]) ++Ans;
            
            UsedNode[{Ny,Nx}]=UsedEdge[{Ny,Nx,Cy,Cx}]=UsedEdge[{Cy,Cx,Ny,Nx}]=true; 
            Cy=Ny;
            Cx=Nx;
        }
    }
    
    return Ans;
}