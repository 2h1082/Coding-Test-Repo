#include <bits/stdc++.h>

using namespace std;
int D=1000000000;
int main()
{
    int N=0;
    cin>>N;
    vector<vector<vector<int>>> DP(N+1,vector<vector<int>>(10,vector<int>(1024,0)));
    
    for(int i=1;i<10;++i)
    {
        DP[1][i][1<<i]=1;
    }
    for(int i=2;i<=N;++i)
    {
        for(int j=0;j<10;++j)
        {
            for(int k=0;k<1024;++k)
            {
                
                int NewK=k|(1<<j);
                if(j>0)
                {
                    DP[i][j][NewK]=(DP[i][j][NewK]+DP[i-1][j-1][k])%D;
                }
                if(j<9)
                {
                    DP[i][j][NewK]=(DP[i][j][NewK]+DP[i-1][j+1][k])%D;
                }
            }
        }
    }
    long long Sum=0;
    for(int i=0;i<10;++i)
    {
        Sum=(Sum+DP[N][i][1023])%D;
    }
    cout<<Sum;
}