#include "bits/stdc++.h"
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    
    vector<vector<int>> Dp(41,vector<int>(2,0));
    Dp[0][0]=Dp[1][1]=1;
    for(int i=2;i<=40;++i)
    {
        Dp[i][0]=Dp[i-1][0]+Dp[i-2][0];
        Dp[i][1]=Dp[i-1][1]+Dp[i-2][1];
    }
    int T;
    cin>>T;
    while(T--)
    {
        int N;
        cin>>N;
        cout<<Dp[N][0]<<' '<<Dp[N][1]<<'\n';
    }
}
/*
0 - 1 0
1 - 0 1
2 - 1 1
3 - 1 2
4 - 2 3
5 - 3 5
6 - 5 8
*/