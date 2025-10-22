#include <bits/stdc++.h>

using namespace std;

int INF=1e9;
int main()
{
    string S;
    cin>>S;
    int N=S.length();
    vector<vector<bool>> DP(N,vector<bool>(N,false));
    for(int i=0;i<N;++i)
    {
        DP[i][i]=true;
    }
    for(int i=0;i<N-1;++i)
    {
        if(S[i]==S[i+1]) DP[i][i+1]=true;
    }
    for(int L=3;L<=N;++L)
    {
        for(int i=0;i<=N-L;++i)
        {
            int j=i+L-1;
            if(S[i]==S[j]&&DP[i+1][j-1]==true) DP[i][j]=true;
        }
    }
    vector<int> Min(N,INF);
    for(int i=0;i<N;++i)
    {
        for(int j=0;j<=i;++j)
        {
            if(DP[j][i]==true)
            {
                if(j==0) 
                {
                    Min[i]=1;
                }
                else
                {
                    Min[i]=min(Min[i],Min[j-1]+1);
                }
            }
        }
    }
    cout<<Min[N-1];
}