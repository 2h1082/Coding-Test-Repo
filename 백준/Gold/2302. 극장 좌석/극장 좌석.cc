#include "bits/stdc++.h"
using namespace std;

int Dp[41];
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    
    int N, M;
    cin>>N>>M;
    Dp[0]=Dp[1]=1;
    Dp[2]=2;
    for(int i=3;i<=40;++i) Dp[i]=Dp[i-2]+Dp[i-1];
    
    int Ans=1, Prev=0;;
    while(M--)
    {
        int Num;
        cin>>Num;
        Ans*=Dp[Num-1-Prev];
        Prev=Num;
    }
    Ans*=Dp[N-Prev];
    cout<<Ans;
}