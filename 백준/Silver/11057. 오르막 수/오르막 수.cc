#include "bits/stdc++.h"
using namespace std;

int Mod=10007;
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    
    int N;
    cin>>N;
    
    vector<int> Dp(10,1);
    for(int l=0;l<N;++l)
    {
        for(int i=1;i<10;++i)
        {
            Dp[i]=(Dp[i]+Dp[i-1])%Mod;
        }
    }
    cout<<Dp[9];
}