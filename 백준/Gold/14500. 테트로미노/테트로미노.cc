#include <iostream>
#include <vector>
#include <queue>

using namespace std;
int N=0,M=0;
vector<vector<int>> Paper;
vector<vector<bool>> Visited;
int dx[4]={0,0,-1,1};
int dy[4]={-1,1,0,0};
int MaxCount=0;
void DFS(int X, int Y,int CurValue,int Count)
{
    if(Count==4)
    {
        MaxCount=max(MaxCount,CurValue);
        return;
    }
    for(int i=0;i<4;++i)
    {
        int NextX=X+dx[i];
        int NextY=Y+dy[i];
        if(NextX>=0&&NextX<M&&NextY>=0&&NextY<N&&!Visited[NextY][NextX])
        {
            Visited[NextY][NextX]=true;
            DFS(NextX,NextY,CurValue+Paper[NextY][NextX],Count+1);
            Visited[NextY][NextX]=false;
        }
    }
    
}
int ComputeEdgeCase(vector<vector<int>>& Paper,int X, int Y)
{
    int Max=0;
    for(int i=0;i<4;++i)
    {
        int CellCount=1;
        int Sum=Paper[Y][X];
        for(int j=0;j<4;++j)
        {
            if(i==j) continue;
            int NextX=X+dx[j];
            int NextY=Y+dy[j];
            if(NextX>=0&&NextX<M&&NextY>=0&&NextY<N)
            {
                Sum+=Paper[NextY][NextX];
                CellCount++;
            }
        }
        if(CellCount==4)
        {
            Max=max(Max,Sum);
        }
    }
    return Max;
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    cin>>N>>M;
    
    Visited.assign(N,vector<bool>(M,false));
    Paper.assign(N,vector<int>(M,0));
    for(int i=0;i<N;++i)
    {
        for(int j=0;j<M;++j)
        {
            cin>>Paper[i][j];
        }
    }
    for(int i=0;i<N;++i)
    {
        for(int j=0;j<M;++j)
        {
            Visited[i][j]=true;
            DFS(j,i,Paper[i][j],1);
            Visited[i][j]=false;
            int Result=ComputeEdgeCase(Paper,j,i);
            MaxCount=max(MaxCount,Result);
        }
    }
    cout<<MaxCount;
}