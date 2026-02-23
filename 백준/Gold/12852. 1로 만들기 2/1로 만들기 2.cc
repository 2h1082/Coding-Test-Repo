#include "bits/stdc++.h"
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    
    int N;
    cin>>N;
    
    vector<int> Dp(N+1,1e9), Prev(N+1,-1);
    Dp[1]=0;
    for(int i=2;i<=N;++i)
    {
        Dp[i]=Dp[i-1]+1;
        Prev[i]=i-1;
        if(i%3==0 && Dp[i/3]+1 < Dp[i])
        {
            Dp[i]=Dp[i/3]+1;
            Prev[i]=i/3;
        }
        if(i%2==0 && Dp[i/2]+1 < Dp[i])
        {
            Dp[i]=Dp[i/2]+1;
            Prev[i]=i/2;
        }
    }
    cout<<Dp[N]<<'\n';
    
    int Cur=N;
    while (1)
    {
        cout<<Cur<<' ';
        if(Cur==1) break;
        Cur=Prev[Cur];
    }
}