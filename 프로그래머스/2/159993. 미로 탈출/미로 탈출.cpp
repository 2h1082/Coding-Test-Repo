#include <bits/stdc++.h>
using namespace std;

int dx[4]={0,0,1,-1};
int dy[4]={1,-1,0,0};
int BFS(vector<string>& Map, int x, int y, char Target, int Row, int Column)
{
    vector<vector<bool>> Visited(Row,vector<bool>(Column,false));
    queue<pair<pair<int,int>,int>> q;
    q.push({{y,x},0});
    Visited[y][x]=true;
    while(!q.empty())
    {
        int CurX=q.front().first.second;
        int CurY=q.front().first.first;
        int Time=q.front().second;
        q.pop();
        
        if(Map[CurY][CurX]==Target) return Time;
        for(int i=0;i<4;i++)
        {
            int Nx=CurX+dx[i];
            int Ny=CurY+dy[i];
            if(Nx>=0&&Nx<Column&&Ny>=0&&Ny<Row&&!Visited[Ny][Nx]&&Map[Ny][Nx]!='X')
            {
                Visited[Ny][Nx]=true;
                q.push({{Ny,Nx},Time+1});
            }
        }
    }
    return -1;
}

int solution(vector<string> maps) {
    int Row=maps.size();
    int Column=maps[0].size();
    int Sx=0, Sy=0;
    int Lx=0, Ly=0;
    for(int y=0;y<Row;y++)
    {
        for(int x=0;x<Column;x++)
        {
            if(maps[y][x]=='S')
            {
                Sx=x;
                Sy=y;
            }
            if(maps[y][x]=='L')
            {
                Lx=x;
                Ly=y;
                break;
            }
        }
    }
    int TimeToLever=BFS(maps,Sx,Sy,'L',Row,Column);
    if(TimeToLever==-1) return -1;
    int TimeToEnd=BFS(maps,Lx,Ly,'E',Row,Column);
    if(TimeToEnd==-1) return -1;
    return TimeToLever+TimeToEnd;
}