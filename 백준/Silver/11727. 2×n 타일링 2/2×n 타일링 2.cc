#include <iostream>
#include <vector>

using namespace std;
int main()
{
    int N=0;
    cin>>N;
    vector<int> Dp(N+1);
    if(N==1)
    {
        cout<<1;
        return 0;
    }
    else if(N==2)
    {
        cout<<3;
        return 0;
    }
    Dp[1]=1;
    Dp[2]=3;
    for(int i=3;i<=N;++i)
    {
        Dp[i]=(Dp[i-2]*2+Dp[i-1])%10007;
    }
    cout<<Dp[N];
}