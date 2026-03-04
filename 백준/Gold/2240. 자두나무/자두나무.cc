#include "bits/stdc++.h"
using namespace std;

int Dp[1001][31][3];
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    
    int T,W;
    cin>>T>>W;
    
    vector<int> A(T+1);
    for(int i=1;i<=T;++i) cin>>A[i];
    
    for(int t=1;t<=T;++t)
    {
        for(int w=0;w<=W;++w)
        {
            if(w==0) Dp[t][w][1]=Dp[t-1][w][1]+(A[t]==1 ? 1 : 0);
            else
            {
                Dp[t][w][1]=max(Dp[t-1][w][1],Dp[t-1][w-1][2]) + (A[t]==1 ? 1 : 0);
                Dp[t][w][2]=max(Dp[t-1][w][2],Dp[t-1][w-1][1]) + (A[t]==2 ? 1 : 0);
            }
        }
    }
    int Ans=0;
    for(int w=0;w<=W;++w) Ans=max({Ans,Dp[T][w][1],Dp[T][w][2]});
    cout<<Ans;
}