#include <iostream>
#include <vector>

using namespace std;
int main()
{
    string S1, S2;
    cin>>S1>>S2;
    int N=S1.size(), M=S2.size();
    vector<vector<int>> DP(N+1,vector<int>(M+1,0));
    for(int i=1;i<=N;++i)
    {
        for(int j=1;j<=M;++j)
        {
            if(S1[i-1]==S2[j-1])
            {
                DP[i][j]=DP[i-1][j-1]+1;
            }
            else
            {
                DP[i][j]=max(DP[i-1][j],DP[i][j-1]);
            }
        }
    }
    cout<<DP[N][M];
}