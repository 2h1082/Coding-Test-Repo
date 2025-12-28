#include "bits/stdc++.h"
using namespace std;

int Dx[]={0,0,-1,1};
int Dy[]={-1,1,0,0};

vector<pair<int,int>> Normalize(vector<pair<int,int>> Shape)
{
    int MinX=100, MinY=100;
    for(auto& P : Shape)
    {
        MinX=min(MinX,P.second);
        MinY=min(MinY,P.first);
    }
    for(int i=0;i<Shape.size();++i)
    {
        Shape[i].first-=MinY;
        Shape[i].second-=MinX;        
    }
    sort(Shape.begin(),Shape.end());
    return Shape;
}
vector<pair<int,int>> Rotate(vector<pair<int,int>> Shape)
{
    for(int i=0;i<Shape.size();++i)
    {
        int Temp=Shape[i].first;
        Shape[i].first= -Shape[i].second;
        Shape[i].second=Temp;
    }
    return Normalize(Shape);
}
vector<pair<int,int>> BFS(vector<vector<int>>& Board, int Sx, int Sy, int Target, int Val)
{
    int N=Board.size();
    queue<pair<int,int>> q;
    vector<pair<int,int>> Ans;
    q.push({Sy,Sx});
    Board[Sy][Sx]=Val;
    Ans.push_back({Sy,Sx});
    
    while(!q.empty())
    {
        auto [Cy, Cx]=q.front();
        q.pop();
        for(int i=0;i<4;++i)
        {
            int Ny=Cy+Dy[i], Nx=Cx+Dx[i];
            if(Ny<0 || Ny>=N || Nx<0 || Nx>=N) continue;
            if(Board[Ny][Nx]!=Target) continue;
            
            q.push({Ny,Nx});
            Board[Ny][Nx]=Val;
            Ans.push_back({Ny,Nx});
        }
    }
    return Normalize(Ans);
}
int solution(vector<vector<int>> Board, vector<vector<int>> Table) 
{
    int N=Board.size();
    vector<vector<pair<int,int>>> Blank, Block;
    
    // 빈칸 모양 추출
    for(int i=0;i<N;++i)
    {
        for(int j=0;j<N;++j)
        {
            if(!Board[i][j]) Blank.push_back(BFS(Board,j,i,0,1));
        }
    }
    // 블록 모양 추출 (테이블)
    for(int i=0;i<N;++i)
    {
        for(int j=0;j<N;++j)
        {
            if(Table[i][j]) Block.push_back(BFS(Table,j,i,1,0));
        }
    }
    
    int Ans=0;
    vector<bool> Used(Block.size(),false);
    for(auto& B : Blank)
    {
        bool bIsFound=false;
        for(int i=0;i<Block.size();++i)
        {
            if(Used[i] || B.size() != Block[i].size()) continue;
            
            vector<pair<int,int>> Cur=Block[i];
            for(int d=0;d<4;++d)
            {
                if(B == Cur)
                {
                    bIsFound=true;
                    Used[i]=true;
                    Ans+=Cur.size();
                    break;
                }
                Cur=Rotate(Cur);
            }
            if(bIsFound) break;
        }
    }
    
    return Ans;
}