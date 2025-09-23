#include <iostream>
#include <vector>

using namespace std;
int main()
{
    int N,K;
    cin>>N>>K;
    vector<vector<int>> Objects(N,vector<int>(2));
    for(int i=0;i<N;++i)
    {
        cin>>Objects[i][0]>>Objects[i][1];
    }
    vector<vector<int>> DP(N+1,vector<int>(K+1,0));
    for(int i=1;i<=N;++i)
    {
        for(int j=1;j<=K;++j)
        {
            if(Objects[i-1][0]<=j)
            {
                DP[i][j]=max(DP[i-1][j],DP[i-1][j-Objects[i-1][0]]+Objects[i-1][1]);
            }
            else
            {
                DP[i][j]=DP[i-1][j];
            }
        }
    }
    cout<<DP[N][K];
}