#include <bits/stdc++.h>

using namespace std;

int solution(vector<string> board) {
    int row=board.size(), col=board[0].size();
    vector<vector<bool>> Visited(row,vector<bool>(col,false));
    queue<tuple<int,int,int>> q; //x,y,count
    
    //find start point
    for(int i=0;i<row;i++)
    {
        for(int j=0;j<col;j++)
        {
            if(board[i][j]=='R')
            {
                q.push({j,i,0});
                Visited[i][j]=true;
            }
        }
    }
    int dx[4]={0,0,-1,1};
    int dy[4]={-1,1,0,0};
    
    while(!q.empty())
    {
        auto [x,y,count]=q.front();
        q.pop();
        
        if(board[y][x]=='G')
        {
            return count;
        }
        for(int i=0;i<4;i++)
        {
            int nx=x, ny=y;
            while(nx+dx[i]>=0&&nx+dx[i]<col&&ny+dy[i]>=0&&ny+dy[i]<row&&board[ny+dy[i]][nx+dx[i]]!='D')
            {
                nx+=dx[i];
                ny+=dy[i];
            }
            if(!Visited[ny][nx])
            {
                Visited[ny][nx]=true;
                q.push({nx,ny,count+1});
            }
        }
    }
    return -1;
}