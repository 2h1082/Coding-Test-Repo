#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int dx[4]={0,0,-1,1};
int dy[4]={-1,1,0,0};
int main()
{
    int M,N;
    cin>>M>>N;
    
    queue<vector<int>> q;
    vector<vector<int>> Box(N,vector<int>(M));
    int Green=0;
    for(int i=0;i<N;++i)
    {
        for(int j=0;j<M;++j)
        {
            cin>>Box[i][j];
            if(Box[i][j]==1)
            {
                q.push({i,j,0});
            }
            else if(Box[i][j]==0)
            {
                Green++;
            }
        }
    }
    if(!Green)
    {
        cout<<"0";
        return 0;
    }
    int MaxCount=0;
    while(!q.empty())
    {
        int CurY=q.front()[0];
        int CurX=q.front()[1];
        int CurDayCount=q.front()[2];
        MaxCount=max(MaxCount,CurDayCount);
        q.pop();
        for(int i=0;i<4;++i)
        {
            int NextX=CurX+dx[i];
            int NextY=CurY+dy[i];
            if(NextX>=0&&NextX<M&&NextY>=0&&NextY<N
              &&Box[NextY][NextX]==0)
            {
                q.push({NextY,NextX,CurDayCount+1});
                Green--;
                Box[NextY][NextX]=1;
            }
        }
    }
    if(Green)
    {
        cout<<"-1 ";
    }
    else
    {
        cout<<MaxCount;
    }
}
