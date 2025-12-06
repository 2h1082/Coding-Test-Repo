#include "bits/stdc++.h"
using namespace std;

vector<int> Dp;
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    int T;
    cin>>T;
    Dp.assign(10001,0);
    Dp[0]=1;
    
    for(int i=1;i<=10000;++i) Dp[i]+=Dp[i-1];
    for(int i=2;i<=10000;++i) Dp[i]+=Dp[i-2];
    for(int i=3;i<=10000;++i) Dp[i]+=Dp[i-3];
    while(T--)
    {
        int N;
        cin>>N;
        
        cout<<Dp[N]<<'\n';
    }
}