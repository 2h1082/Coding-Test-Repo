#include <iostream>
#include <vector>

using namespace std;
int N=0;
vector<vector<int>> Blocks;
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
    vector<vector<vector<int>>> DP(N,vector<vector<int>>(N,vector<int>(3,0)));
    DP[0][1][0]=1;
    for(int r=0;r<N;++r)
    {
        for(int c=2;c<N;++c)
        {
            if(!Blocks[r][c])
            {
                DP[r][c][0]=DP[r][c-1][0]+DP[r][c-1][2];
                if(r>0)
                {
                    DP[r][c][1]=DP[r-1][c][1]+DP[r-1][c][2];
                }
                if(r>0&&c>0&&!Blocks[r-1][c]&&!Blocks[r][c-1])
                {
                    DP[r][c][2]=DP[r-1][c-1][0]+DP[r-1][c-1][1]+DP[r-1][c-1][2];
                }
            }
        }
    }
    
    cout<<DP[N-1][N-1][0]+DP[N-1][N-1][1]+DP[N-1][N-1][2];
}
