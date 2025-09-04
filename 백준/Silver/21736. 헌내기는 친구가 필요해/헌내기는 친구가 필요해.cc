#include <iostream>
#include <vector>
#include <queue>

using namespace std;
int Dx[4]={0,0,-1,1};
int Dy[4]={-1,1,0,0};
int main()
{
    int N=0,M=0;
    cin>>N>>M;
    vector<string> Campus(N);
    queue<pair<int,int>> q;
    for(int i=0;i<N;++i)
    {
        for(int j=0;j<M;++j)
        {
            char C;
            cin>>C;
            if(C=='I')
            {
                q.push({i,j});
            }
            Campus[i]+=C;
        }
    }
    vector<vector<bool>> Visited(N,vector<bool>(M,false));
    int Count=0;
    while(!q.empty())
    {
        int CurY=q.front().first;
        int CurX=q.front().second;
        q.pop();
        if (Visited[CurY][CurX]) continue;
        Visited[CurY][CurX]=true;
        if(Campus[CurY][CurX]=='P')
        {
            Count++;
        }
        for(int i=0;i<4;++i)
        {
            int NextX=CurX+Dx[i];
            int NextY=CurY+Dy[i];
            if(NextY>=0&&NextY<N&&NextX>=0&&NextX<M
                &&!Visited[NextY][NextX]&&Campus[NextY][NextX]!='X')
            {
                q.push({NextY,NextX});
            }
        }
    }
    if(Count>0) cout<<Count;
    else        cout<<"TT";
}