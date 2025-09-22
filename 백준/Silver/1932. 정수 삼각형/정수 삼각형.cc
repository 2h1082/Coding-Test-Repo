#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int N=0;
vector<vector<int>> Triangle;
vector<vector<int>> DP;
int main()
{
    cin>>N;
    Triangle.assign(N,vector<int>());
    for(int i=0;i<N;++i)
    {
        for(int j=0;j<=i;++j)
        {
            int Num=0;
            cin>>Num;
            Triangle[i].push_back(Num);
        }
    }
    DP.assign(N,vector<int>(N,0));
    DP[0][0]=Triangle[0][0];
    for(int i=1;i<N;++i)
    {
        for(int j=0;j<i;++j)
        {
            DP[i][j]=max(DP[i][j],Triangle[i][j]+DP[i-1][j]);
            DP[i][j+1]=Triangle[i][j+1]+DP[i-1][j];
        }
    }
    int Max=*max_element(DP[N-1].begin(),DP[N-1].end());
    cout<<Max;
}