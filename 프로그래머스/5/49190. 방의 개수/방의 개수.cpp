#include "bits/stdc++.h"
using namespace std;

int Dx[]={0,1,1,1,0,-1,-1,-1};
int Dy[]={1,1,0,-1,-1,-1,0,1};
int solution(vector<int> Arrows) 
{
    int Ans = 0;
    map<pair<int,int>, bool> UsedNode;
    map<tuple<int,int,int,int>, bool> UsedEdge;
    UsedNode[{0,0}]=true;
    int Cx=0, Cy=0;
    for(auto& A : Arrows)
    {
        for(int i=0;i<2;++i)
        {
            int Ny=Cy+Dy[A], Nx=Cx+Dx[A];
            if(UsedNode[{Ny,Nx}] && !UsedEdge[{Cy,Cx,Ny,Nx}] && !UsedEdge[{Ny,Nx,Cy,Cx}])
            {
                Ans++;
            }
            
            UsedNode[{Ny,Nx}]=true;
            UsedEdge[{Cy,Cx,Ny,Nx}]=UsedEdge[{Ny,Nx,Cy,Cx}]=true;
            Cy=Ny;
            Cx=Nx;
        }
    }
    return Ans;
}