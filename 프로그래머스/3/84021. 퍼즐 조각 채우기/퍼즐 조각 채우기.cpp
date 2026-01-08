#include "bits/stdc++.h"
using namespace std;

int Dx[]={0,0,-1,1};
int Dy[]={-1,1,0,0};

void Normalize(vector<pair<int,int>>& Block)
{
    int MinX=1e9, MinY=1e9;
    for(auto& [y,x] : Block)
    {
        MinX=min(MinX,x);
        MinY=min(MinY,y);
    }
    for(auto& [y,x] : Block)
    {
        y-=MinY;
        x-=MinX;
    }
    // 정렬 (정렬되어 있어야 올바른 비교 가능)
    sort(Block.begin(),Block.end());
}
void Rotate(vector<pair<int,int>>& Block)
{
    for(auto& [y,x] : Block)
    {
        int Temp=y;
        y=x;
        x=-Temp;
    }
    Normalize(Block);
}
vector<pair<int,int>> BFS(vector<vector<int>>& Map, int Sx, int Sy, int Target, int Val)
{
    int N=Map.size();
    vector<pair<int,int>> Ans(1,{Sy,Sx});
    
    queue<pair<int,int>> Q;
    Q.push({Sy,Sx});
    Map[Sy][Sx]=Val;
    
    while(!Q.empty())
    {
        auto [Cy,Cx]=Q.front();
        Q.pop();
        for(int i=0;i<4;++i)
        {
            int Ny=Cy+Dy[i], Nx=Cx+Dx[i];
            if(Ny<0 || Ny>=N || Nx<0 || Nx>=N) continue;
            if(Map[Ny][Nx]!=Target)            continue;
            
            Q.push({Ny,Nx});
            Ans.push_back({Ny,Nx});
            Map[Ny][Nx]=Val;
        }
    }
    
    Normalize(Ans);
    return Ans;
}
int solution(vector<vector<int>> Board, vector<vector<int>> Table) 
{
    int N=Board.size();
    
    vector<vector<pair<int,int>>> Blank, Block;
    // 빈칸 모양 탐색
    for(int i=0;i<N;++i)
    {
        for(int j=0;j<N;++j)
        {
            if(!Board[i][j]) Blank.push_back(BFS(Board,j,i,0,1));
        }
    }
    
    // 테이블의 블럭 모양 탐색
    for(int i=0;i<N;++i)
    {
        for(int j=0;j<N;++j)
        {
            if(Table[i][j]) Block.push_back(BFS(Table,j,i,1,0));
        }
    }
    
    // 모양 대조하며 맞춰보기
    vector<bool> Used(Blank.size(),false);
    int Cnt=0, M=Block.size();
    for(auto& Cur : Blank)
    {
        int CurSize=Cur.size();
        for(int i=0;i<M;++i)
        {
            int BlockCnt=Block[i].size();
            if(CurSize!=BlockCnt || Used[i]) continue;

            bool bIsMatch=false;
            for(int d=0;d<4;++d)
            {
                if(Cur==Block[i])
                {
                    Cnt+=CurSize;
                    Used[i]=true;
                    bIsMatch=true;
                    break;
                }
                Rotate(Block[i]);
            }
            if(bIsMatch) break;
        }
    }
    
    return Cnt;
}