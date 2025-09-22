#include <iostream>
#include <vector>

using namespace std;
int N,M;
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    cin>>N>>M;
    vector<vector<int>> Graph(N,vector<int>(N,0));
    vector<vector<long long>> DP(N,vector<long long>(N,0));
    for(int i=0;i<N;++i)
    {
        for(int j=0;j<N;++j)
        {
            cin>>Graph[i][j];
            DP[i][j]=Graph[i][j];
            if(j>0)
            {
                DP[i][j]+=DP[i][j-1];
            }
            if(i>0)
            {
                DP[i][j]+=DP[i-1][j];
            }
            if(i>0&&j>0)
            {
                DP[i][j]-=DP[i-1][j-1];
            }
        }
    }
    while(M--)
    {
        int X1,X2,Y1,Y2;
        cin>>Y1>>X1>>Y2>>X2;
        long long Sum=DP[Y2-1][X2-1];
        if(X1>1)
        {
            Sum-=DP[Y2-1][X1-2];
        }
        if(Y1>1)
        {
            Sum-=DP[Y1-2][X2-1];
        }
        if(X1>1&&Y1>1)
        {
            Sum+=DP[Y1-2][X1-2];
        }
        
        cout<<Sum<<"\n";
    }
}