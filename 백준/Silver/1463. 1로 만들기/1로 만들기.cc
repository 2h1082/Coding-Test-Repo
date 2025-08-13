#include <iostream>
#include <vector>

using namespace std;
int main()
{
    int N=0;
    cin>>N;
    vector<int> Dp(N+1,0);
    for(int i=2;i<=N;++i)
    {
        Dp[i]=Dp[i-1]+1;
        if(i%2==0) Dp[i]=min(Dp[i],Dp[i/2]+1);
        if(i%3==0) Dp[i]=min(Dp[i],Dp[i/3]+1);
    }
    cout<<Dp[N];
}