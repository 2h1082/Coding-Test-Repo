#include "bits/stdc++.h"
using namespace std;

int Mod=1e9;
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    
    int N;
    cin>>N;
    
    // 자리수, 마지막 수 형태로 관리
    // Dp[5][1] : 5자리 수, 끝의 수 1
    vector<vector<int>> Dp(N+1,vector<int>(10,0));
    for(int i=1;i<10;++i) Dp[1][i]=1;
    
    for(int i=2;i<=N;++i)
    {
        for(int j=0;j<10;++j)
        {
            if(j==0)      Dp[i][j]=Dp[i-1][1];
            else if(j==9) Dp[i][j]=Dp[i-1][8];
            else          Dp[i][j]=(Dp[i-1][j-1]+Dp[i-1][j+1])%Mod;
        }
    }
    int Ans=0;
    for(int A : Dp[N]) Ans=(Ans+A)%Mod;
    cout<<Ans;
}