#include <iostream>
#include <vector>

using namespace std;
int main()
{
    int N=0;
    cin>>N;
    vector<int> Stairs(N);
    for(int i=0;i<N;++i)
    {
        cin>>Stairs[i];
    }
    vector<int> Dp=Stairs;
    Dp[1]+=Dp[0];
    Dp[2]+=max(Stairs[1],Stairs[0]);
    for(int i=3;i<N;++i)
    {
        Dp[i]=max(Dp[i-2],Dp[i-3]+Stairs[i-1])+Stairs[i];
    }
    cout<<Dp[N-1];
}