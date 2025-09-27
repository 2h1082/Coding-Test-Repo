#include <iostream>
#include <vector>

using namespace std;
int R=0,C=0;
int Max=0;
vector<string> Board;
vector<bool> Visited(26,false);
int dx[4]={0,0,-1,1};
int dy[4]={-1,1,0,0};
void DFS(int X, int Y,int Count)
{
    Max=max(Max,Count);
    for(int i=0;i<4;++i)
    {
        int NextX=dx[i]+X;
        int NextY=dy[i]+Y;
        if(NextX>=0&&NextX<C&&NextY>=0&&NextY<R&&!Visited[Board[NextY][NextX]-'A'])
        {
            Visited[Board[NextY][NextX]-'A']=true;
            DFS(NextX,NextY,Count+1);
            Visited[Board[NextY][NextX]-'A']=false;            
        }
    }
}
int main()
{
    cin>>R>>C;
    Board.assign(R,string());
    for(int i=0;i<R;++i)
    {
        cin>>Board[i];
    }
    Visited[Board[0][0]-'A']=true;
    DFS(0,0,1);
    cout<<Max;
}