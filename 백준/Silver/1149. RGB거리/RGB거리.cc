#include <iostream>
#include <vector>
#include <climits>

using namespace std;
int N=0;
int Min=INT_MAX;
vector<vector<int>> Cost;
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    cin>>N;
    Cost.assign(N,vector<int>(3));
    for(int i=0;i<N;++i)
    {
        for(int j=0;j<3;++j)
        {
            cin>>Cost[i][j];
        }
    }
    vector<vector<int>> DP(N,vector<int>(3));
    DP[0][0]=Cost[0][0];
    DP[0][1]=Cost[0][1];
    DP[0][2]=Cost[0][2];
    for(int i=1;i<N;++i)
    {
        DP[i][0]=Cost[i][0]+min(DP[i-1][1],DP[i-1][2]);
        DP[i][1]=Cost[i][1]+min(DP[i-1][0],DP[i-1][2]);
        DP[i][2]=Cost[i][2]+min(DP[i-1][1],DP[i-1][0]);
    }
    Min=min(DP[N-1][0],DP[N-1][1]);
    Min=min(DP[N-1][2],Min);
    cout<<Min;
}