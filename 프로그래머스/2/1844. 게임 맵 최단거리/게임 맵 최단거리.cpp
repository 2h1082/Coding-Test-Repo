#include<bits/stdc++.h>
using namespace std;
int dx[4]={1,0,-1,0};
int dy[4]={0,1,0,-1};
int solution(vector<vector<int> > maps)
{
    int answer = 0;
    int n=maps.size();
    int m=maps[0].size();
    vector<vector<bool>> visited(n,vector<bool>(m,false));
    queue<tuple<int,int,int>> q;
    q.push({0,0,1});
    visited[0][0]=true;
    while(!q.empty())
    {
        int x=get<1>(q.front());
        int y=get<0>(q.front());
        int count=get<2>(q.front());
        q.pop();
        if(x==m-1&&y==n-1)
        {
            return count;
        }
        for(int i=0;i<4;i++)
        {
            int nx=x+dx[i];
            int ny=y+dy[i];
            if(ny<0||ny>=n||nx<0||nx>=m) continue;
            if(!visited[ny][nx]&&maps[ny][nx]==1)
            {
                q.push({ny,nx,count+1});
                visited[ny][nx]=true;
            }
        }
    }
    return -1;
}