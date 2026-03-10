#include "bits/stdc++.h"
using namespace std;

int Dp[1000001];
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    
    int N;
    cin>>N;
    
    int Abs=abs(N);
    Dp[1]=1;
    for(int i=2;i<=Abs;++i) Dp[i]=(Dp[i-1]+Dp[i-2])%1000000000;
    int Sign=1;
    if(N==0)     Sign=0;
    else if(N<0) Sign= Abs%2==0 ? -1 : 1;
    
    cout<<Sign<<'\n'<<Dp[Abs];
}