#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int Dx[4]={-1,1,0,0};
int Dy[4]={0,0,-1,1};
int BFS(int M, int N, vector<vector<int>> Grid)
{
    int Count=0;
    for(int i=0;i<M;++i)
    {
        for(int j=0;j<N;++j)
        {
            if(Grid[i][j]==1)
            {
                Count++;
                queue<pair<int,int>> Q;
                Q.push({i,j});
                while(!Q.empty())
                {
                    int X=Q.front().first;
                    int Y=Q.front().second;
                    Q.pop();
                    for(int k=0;k<4;++k)
                    {
                        int Nx=X+Dx[k];
                        int Ny=Y+Dy[k];
                        if(Nx>=0&&Nx<M&&Ny>=0&&Ny<N)
                        {
                            if(Grid[Nx][Ny]==1) 
                            {
                                Grid[Nx][Ny]=0;
                                Q.push({Nx,Ny});
                            }
                        }
                    }
                }
            }
        }
    }
    return Count;
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int T=0;
    cin>>T;
    while(T--)
    {
        int M=0, N=0, K=0;
        cin>>M>>N>>K;
        vector<vector<int>> Grid(M,vector<int>(N,0));
        for(int i=0;i<K;++i)
        {
            int X=0,Y=0;
            cin>>X>>Y;
            Grid[X][Y]=1;
        }
        int Answer=BFS(M,N,Grid);
        cout<<Answer<<"\n";
    }
}
