#include <iostream>
#include <vector>
#include <climits>

using namespace std;

int main()
{
    int N=0, Count=0;
    cin>>N;
    vector<int> Dp(N+1,INT_MAX);
    Dp[0]=0;
    Dp[1]=1;
    for (int i=2;i<=N;++i)
    {
        for (int j=1;j*j<=i;++j)
        {
            Dp[i]=min(Dp[i],Dp[i-j*j]+1);
        }
    }
    cout<<Dp[N];
}