#include "bits/stdc++.h"
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    
    int N;
    cin>>N;
    
    vector<int> Dp(N+1,1e9), Prev(N+1,-1);
    Dp[N]=0;
    for(int i=N;i>=1;--i)
    {
        int NxtIdx=0, NxtVal=Dp[i]+1;;
        if(i%3==0)
        {
            NxtIdx=i/3;
            if(NxtVal < Dp[NxtIdx]) 
            {
                Dp[NxtIdx]=NxtVal;
                Prev[NxtIdx]=i;
            }
        }
        if(i%2==0)
        {
            NxtIdx=i/2;
            if(NxtVal < Dp[NxtIdx]) 
            {
                Dp[NxtIdx]=NxtVal;
                Prev[NxtIdx]=i;
            }
        }
        NxtIdx=i-1;
        if(NxtVal < Dp[NxtIdx]) 
        {
            Dp[NxtIdx]=NxtVal;
            Prev[NxtIdx]=i;
        }
    }
    cout<<Dp[1]<<'\n';
    
    int Cur=1;
    vector<int> Ans;
    while (Prev[Cur]!=-1)
    {
        Ans.push_back(Cur);
        Cur=Prev[Cur];
    }
    cout<<N<<' ';
    for(auto It=Ans.rbegin();It!=Ans.rend();++It) cout<<*It<<' ';
}