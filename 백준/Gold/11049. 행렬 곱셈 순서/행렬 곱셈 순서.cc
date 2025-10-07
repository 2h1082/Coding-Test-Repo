#include <bits/stdc++.h>

using namespace std;

int main()
{
    int N=0;
    cin>>N;
    vector<pair<int,int>> Matrix(N);
    for(int i=0;i<N;++i)
    {
        cin>>Matrix[i].first>>Matrix[i].second;
    }
    vector<vector<int>> DP(N,vector<int>(N,INT_MAX));
    for(int i=0;i<N;++i) DP[i][i]=0;
    for(int L=2;L<=N;++L)
    {
        for(int i=0;i<N-L+1;++i)
        {
            int j=i+L-1;
            for(int k=i;k<j;++k)
            {
                DP[i][j]=min(DP[i][j],DP[i][k]+DP[k+1][j]+Matrix[i].first*Matrix[k].second*Matrix[j].second);
            }
        }
    }
    cout<<DP[0][N-1];
}