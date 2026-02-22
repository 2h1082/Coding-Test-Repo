#include "bits/stdc++.h"
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    
    int N;
    cin>>N;
    vector<vector<int>> Dp(N,vector<int>(3)), A(N,vector<int>(3));
    for(auto& r : A)  cin>>r[0]>>r[1]>>r[2];
    Dp[0][0]=A[0][0];
    Dp[0][1]=A[0][1];
    Dp[0][2]=A[0][2];
    for(int i=1;i<N;++i)
    {
        Dp[i][0]=min(Dp[i-1][1],Dp[i-1][2])+A[i][0];
        Dp[i][1]=min(Dp[i-1][0],Dp[i-1][2])+A[i][1];
        Dp[i][2]=min(Dp[i-1][1],Dp[i-1][0])+A[i][2];
    }
    cout<<*min_element(Dp[N-1].begin(),Dp[N-1].end());
}