#include "bits/stdc++.h"
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    int N=0, M=0;
    cin>>N;
    vector<int> Num(N,0);
    int Sum=0;
    for(auto& n : Num)
    {
        cin>>n;
        Sum+=n;
    }
    vector<vector<bool>> Dp(N+1,vector<bool>(Sum+1,false));
    Dp[0][0]=true;
    for(int i=1;i<=N;++i)
    {
        int w=Num[i-1];
        for(int Diff=0;Diff<=Sum;++Diff)
        {
            if(Dp[i-1][Diff])                     Dp[i][Diff]=true;
            if(Diff+w<=Sum && Dp[i-1][Diff+w])    Dp[i][Diff]=true;
            int AbsDiff=abs(Diff-w);
            if(AbsDiff<=Sum && Dp[i-1][AbsDiff])  Dp[i][Diff]=true;
        }
    }
    
    cin>>M;
    while(M--)
    {
        int Marble;
        cin>>Marble;
        if(Marble>Sum)
        {
            cout<<"N ";
            continue;
        }
        if(Dp[N][Marble]) cout<<"Y ";
        else              cout<<"N ";
    }
}