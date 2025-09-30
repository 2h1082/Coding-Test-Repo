#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int N=0, M=0, Max=0;
vector<vector<int>> OriginMap;

int dx[4]={0,0,-1,1};
int dy[4]={-1,1,0,0};
int Count=0;
queue<pair<int,int>> q;
void BFS(vector<vector<int>> Map)
{
    int ZeroCount=Count-3;
    queue<pair<int,int>> Q=q;
    while(!Q.empty())
    {
        int X=Q.front().first;
        int Y=Q.front().second;
        Q.pop();
        for(int i=0;i<4;++i)
        {
            int NextX=X+dx[i];
            int NextY=Y+dy[i];
            if(NextX>=0&&NextX<M&&NextY>=0&&NextY<N&&!Map[NextY][NextX])
            {
                Map[NextY][NextX]=2;
                Q.push({NextX,NextY});
                ZeroCount--;
            }
        }
    }
    Max=max(Max,ZeroCount);
}

void PlaceWalls(int Index, int WallCount)
{
    if (WallCount==3)
    {
        BFS(OriginMap);
        return;
    }
    
    for(int k=Index;k<N*M;++k)
    {
        int i=k/M;
        int j=k%M;
        if(OriginMap[i][j]==0)
        {
            OriginMap[i][j]=1;
            PlaceWalls(k+1,WallCount+1);
            OriginMap[i][j]=0;                
        }
    }
    
}
    
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    cin>>N>>M;
    OriginMap.assign(N,vector<int>(M,0));
    
    for(int i=0;i<N;++i)
    {
        for(int j=0;j<M;++j)
        {
            cin>>OriginMap[i][j];
            if(OriginMap[i][j]==2)
            {
                q.push({j,i}); //X, Y
            }
            else if(!OriginMap[i][j]) 
            {
                Count++;
            }
        }
    }
    PlaceWalls(0,0);
    cout<<Max;
}