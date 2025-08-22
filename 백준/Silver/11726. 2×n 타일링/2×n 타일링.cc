#include <iostream>
#include <vector>

using namespace std;
int main()
{
    int N=0;
    cin>>N;
    vector<long long> Dp(N+1);
    Dp[1]=1;
    Dp[2]=2;
    for(int i=3;i<=N;++i)
    {
        Dp[i]=(Dp[i-2]+Dp[i-1])%10007;
    }
    cout<<Dp[N]<<"\n";
}