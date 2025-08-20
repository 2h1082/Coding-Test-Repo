#include <iostream>
#include <vector>

using namespace std;
int main()
{
    int T=0;
    cin>>T;
    vector<long long> Dp(101);
    int Limit=5;
    Dp[1]=1;
    Dp[2]=1;
    Dp[3]=1;
    Dp[4]=2;
    Dp[5]=2;
    while(T--)
    {
        int N=0;
        cin>>N;
        for(;Limit<=N;++Limit)
        {
            Dp[Limit]=Dp[Limit-1]+Dp[Limit-5];
        }
        cout<<Dp[N]<<"\n";
    }
}     