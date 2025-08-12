#include <iostream>
#include <vector>
#include <climits>
#include <cmath>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
   
    int T=0;
    cin>>T;
    vector<int> Q(T);
    int Max=0;
    for(int i=0;i<T;++i)
    {
        cin>>Q[i];
        Max=max(Q[i],Max);
    }
    vector<vector<int>> Dp(Max+1,vector<int>(2,0));
    Dp[0][0]=1;
    if(Max!=0) Dp[1][1]=1;
    for(int i=2;i<=Max;++i)
    {
        Dp[i][0]=Dp[i-2][0]+Dp[i-1][0];
        Dp[i][1]=Dp[i-2][1]+Dp[i-1][1];
    }
    for(auto& Test:Q)
    {
        cout<<Dp[Test][0]<<" "<<Dp[Test][1]<<"\n";
    }
}
/*
    0  1
0 - 1, 0
1 - 0, 1
2 - 1, 1
3 - 1, 2
4 - 2  3
5 - 3  5
6 - 5  8
*/