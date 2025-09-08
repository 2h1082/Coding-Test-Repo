#include <iostream>
#include <vector>
#include <queue>

using namespace std;
int dx[4]={0,0,-1,1};
int dy[4]={-1,1,0,0};
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int N=0,M=0;
    cin>>N>>M;
    
    vector<string> Maze(N);
    for(int i=0;i<N;++i)
    {
        cin>>Maze[i];
    }
    queue<vector<int>> q;
    vector<vector<bool>> Visited(N,vector<bool>(M,false));
    q.push({0,0,1});
    int Result=0;
    while(!q.empty())
    {
        int y=q.front()[0];
        int x=q.front()[1];
        int Count=q.front()[2];
        q.pop();
        if(y==N-1&&x==M-1)
        {
            Result=Count;
            break;
        } 
        for(int i=0;i<4;++i)
        {
            int ny=y+dy[i];
            int nx=x+dx[i];
            if(ny>=0&&ny<N&&nx>=0&&nx<M&&!Visited[ny][nx]&&Maze[ny][nx]=='1')
            {
                q.push({ny,nx,Count+1});
                Visited[ny][nx]=true;
            }
        }
    }
    cout<<Result;
}