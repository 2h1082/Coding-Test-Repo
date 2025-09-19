#include <iostream>
#include <queue>
#include <vector>

using namespace std;
int dx[4]={0,0,-1,1};
int dy[4]={-1,1,0,0};
int N=0;
void BFS(vector<string>& Grid, vector<vector<bool>>& Visited, int X, int Y, int bIsColorBlind)
{
    queue<vector<int>> q;
    q.push({X,Y});
    while(!q.empty())
    {
        int CurX=q.front()[0];
        int CurY=q.front()[1];
        q.pop();
        for(int i=0;i<4;++i)
        {
            int NextX=CurX+dx[i];
            int NextY=CurY+dy[i];
            if(NextX>=0&&NextX<N&&NextY>=0&&NextY<N&&!Visited[NextY][NextX])
            {
                if(Grid[Y][X]==Grid[NextY][NextX] ||
                   (Grid[Y][X]!='B'&&bIsColorBlind&&Grid[NextY][NextX]!='B'))
                {
                    Visited[NextY][NextX]=true;
                    q.push({NextX,NextY});
                }
            }
        }
    }
}
int main()
{
    cin>>N;
    vector<string> Grid(N);
    for(int i=0;i<N;++i)
    {
        cin>>Grid[i];
    }
    for(int k=0;k<2;++k)
    {
        vector<vector<bool>> Visited(N,vector<bool>(N,false));
        int Count=0;
        for(int i=0;i<N;++i)
        {
            for(int j=0;j<N;++j)
            {
                if(!Visited[i][j])
                {
                    BFS(Grid,Visited,j,i,k);
                    Visited[i][j]=true;
                    Count++;
                }
            }
        }
        cout<<Count<<" ";
    }
}