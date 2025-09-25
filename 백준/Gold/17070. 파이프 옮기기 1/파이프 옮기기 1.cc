#include <iostream>
#include <vector>

using namespace std;
int N=0;
int Count=0;
vector<vector<int>> Blocks;
int dx[3]={1,0,1};
int dy[3]={0,1,1};
void DFS(int X, int Y, int Type)
{
    if(X==N-1&&Y==N-1)
    {
        Count++;
        return;
    }
    int NextX=0;
    int NextY=0;
    if (Type==0||Type==2)
    {
        NextX=X+dx[0];
        NextY=Y+dy[0];
        if (NextX<N&&NextY<N&&!Blocks[NextY][NextX])
        {
            DFS(NextX,NextY,0);
        }
    }
    if (Type==1||Type==2)
    {
        NextX=X+dx[1];
        NextY=Y+dy[1];
        if (NextX<N&&NextY<N&&!Blocks[NextY][NextX])
        {
            DFS(NextX,NextY,1);
        }
    }
    NextX=X+dx[2];
    NextY=Y+dy[2];
    if (NextX<N&&NextY<N&&!Blocks[NextY][NextX]&&!Blocks[NextY][X]&&!Blocks[Y][NextX])
    {
        DFS(NextX,NextY,2);
    }
    
}
int main()
{
    cin>>N;
    Blocks.assign(N,vector<int>(N,0));
    for(int i=0;i<N;++i)
    {
        for(int j=0;j<N;++j)
        {
            cin>>Blocks[i][j];
        }
    }
    DFS(1,0,0); // 0 : ㅡ, 1 : |, 2 : 
    cout<<Count;
}
