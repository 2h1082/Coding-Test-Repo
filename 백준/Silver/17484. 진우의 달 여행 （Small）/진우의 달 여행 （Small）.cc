#include "bits/stdc++.h"
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    int N,M;
    cin>>N>>M;
    
    vector<vector<int>> B(N,vector<int>(M,0));
    vector<vector<vector<int>>> Dp(N,vector<vector<int>>(M,vector<int>(3,1e9)));
    for(auto& r : B)
    {
        for(auto& c : r)
        {
            cin>>c;
        }
    }
    
    for(int i=0;i<M;++i)
        for (int d=0;d<3;++d)
            Dp[0][i][d]=B[0][i];
    
    for(int i=1;i<N;++i)
    {
        for(int j=0;j<M;++j)
        {
            for (int d=0;d<3;++d)
            {
                int Pj=j;
                if (d==0) Pj=j-1;
                if (d==2) Pj=j+1;

                if (Pj<0 || Pj>=M) continue;
                for (int Pd=0;Pd<3;++Pd)
                {
                    if (Pd==d) continue;

                    Dp[i][j][d]=min(Dp[i][j][d],Dp[i-1][Pj][Pd]+B[i][j]);
                }
            }
        }
    }
    int Ans=1e9;
    for (int i=0;i<M;++i)
    {
        for (int d=0;d<3;++d)
        {
            Ans=min(Ans,Dp[N-1][i][d]);
        }
    }
    cout<<Ans;
}