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
    vector<vector<int>> Map(N,vector<int>(M));
    vector<vector<bool>> Visited(N,vector<bool>(M,false));
    queue<vector<int>> q;
    int InitX=0, InitY=0;
    for(int i=0;i<N;++i)
    {
        for(int j=0;j<M;++j)
        {
            cin>>Map[i][j];
            if(Map[i][j]==2)
            {
                Map[i][j]=0;
                q.push({i,j,0});
                InitX=j;
                InitY=i;
            }
        }
    }
    
    while(!q.empty())
    {
        int CurY=q.front()[0];
        int CurX=q.front()[1];
        int Count=q.front()[2];
        q.pop();
        for(int i=0;i<4;++i)
        {
            int NextY=CurY+dy[i];
            int NextX=CurX+dx[i];
            if(NextY>=0 && NextY<N && NextX>=0 && NextX<M
              && !Visited[NextY][NextX] && Map[NextY][NextX]==1)
            {
                q.push({NextY,NextX,Count+1});
                Visited[NextY][NextX]=true;
                Map[NextY][NextX]=Count+1;
            }
        }
    }
    for(int i=0;i<N;++i)
    {
        for(int j=0;j<M;++j)
        {
            if(Map[i][j]==1&& (abs(InitX-j)+abs(InitY-i))!=1)
            {
                Map[i][j]=-1;
            }
            cout<<Map[i][j]<<" ";
        }
        cout<<"\n";
    }
}