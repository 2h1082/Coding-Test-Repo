#include "bits/stdc++.h"
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    
    int N;
    cin>>N;
    vector<vector<int>> Dp(N,vector<int>(N,0)), A(N);
    for(int i=0;i<N;++i)
    {
        for(int j=0;j<=i;++j)
        {
            int Num;
            cin>>Num;
            A[i].push_back(Num);
        }
    }
    Dp[0][0]=A[0][0];
    for(int i=1;i<N;++i)
    {
        for(int j=0;j<=i;++j)
        {
            Dp[i][j]=max(Dp[i][j],Dp[i-1][j]+A[i][j]);
            if(j>0) Dp[i][j]=max(Dp[i][j],Dp[i-1][j-1]+A[i][j]);
        }
    }
    cout<<*max_element(Dp[N-1].begin(), Dp[N-1].end());
}