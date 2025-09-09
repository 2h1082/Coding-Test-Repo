#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

int dx[4]={0,0,-1,1};
int dy[4]={-1,1,0,0};
int BFS(vector<vector<bool>>& Visited, vector<string>& Square, int y, int x, int N)
{
    queue<pair<int,int>> q;
    q.push({x,y});
    Visited[y][x]=true;
    int Count=1;
    while(!q.empty())
    {
        int CurX=q.front().first;
        int CurY=q.front().second;
        q.pop();
        for(int i=0;i<4;++i)
        {
            int NextX=CurX+dx[i];
            int NextY=CurY+dy[i];
            if(NextX>=0&&NextX<N&&NextY>=0&&NextY<N
               &&!Visited[NextY][NextX]&&Square[NextY][NextX]=='1')
            {
                Visited[NextY][NextX]=true;
                Count++;
                q.push({NextX,NextY});
            }
        }
    }
    return Count;
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int N=0;
    cin>>N;
    vector<string> Square(N);
    for(int i=0;i<N;++i)
    {
        cin>>Square[i];
    }
    vector<vector<bool>> Visited(N,vector<bool>(N,false));
    vector<int> TotalCount;
    for(int i=0;i<N;++i)
    {
        for(int j=0;j<N;++j)
        {
            if(Square[i][j]=='1'&&!Visited[i][j])
            {
                int Count=BFS(Visited,Square,i,j,N);
                TotalCount.push_back(Count);
            }
        }
    }
    sort(TotalCount.begin(),TotalCount.end());
    cout<<TotalCount.size();
    for(auto& C : TotalCount)
    {
        cout<<"\n"<<C;
    }
}