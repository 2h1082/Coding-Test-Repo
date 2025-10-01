#include <iostream>
#include <vector>
#include <queue>
#include <climits>

using namespace std;
int dx[4]={0,0,-1,1};
int dy[4]={-1,1,0,0};
int main()
{
    int N=0,M=0;
    cin>>N>>M;
    vector<string> Map(N);
    for(auto& R : Map)
    {
        cin>>R;
    }
    queue<vector<int>> q;
    vector<vector<vector<bool>>> Visited(N,vector<vector<bool>>(M,vector<bool>(2,false)));
    q.push({0,0,1,1}); //x, y, Count, CanBreakWallCount
    Visited[0][0][1]=true;
    while(!q.empty())
    {
        int X=q.front()[0];
        int Y=q.front()[1];
        int CurCount=q.front()[2];
        int WallCount=q.front()[3];
        q.pop();
        if(X==M-1&&Y==N-1)
        {
            cout<<CurCount;
            return 0;
        }
        for(int i=0;i<4;++i)
        {
            int NextX=X+dx[i];
            int NextY=Y+dy[i];
            if(NextX>=0&&NextX<M&&NextY>=0&&NextY<N)
            {
                if(Map[NextY][NextX]=='1'&&WallCount>0&&!Visited[NextY][NextX][WallCount-1])
                {
                    Visited[NextY][NextX][WallCount-1]=true;
                    q.push({NextX,NextY,CurCount+1,WallCount-1});
                }
                else if(Map[NextY][NextX]=='0'&&!Visited[NextY][NextX][WallCount])
                {
                    Visited[NextY][NextX][WallCount]=true;
                    q.push({NextX,NextY,CurCount+1,WallCount});
                }
            }
        }
    }
    cout<<"-1";
}