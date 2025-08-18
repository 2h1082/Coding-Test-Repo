#include <iostream>
#include <vector>

using namespace std;
int main()
{
    int T=0;
    cin>>T;
    vector<int> V(T);
    int Max=0;
    for(int i=0;i<T;++i)
    {
        cin>>V[i];
        Max=max(V[i],Max);
    }
    vector<int> Dp(Max+1);
    Dp[1]=1;
    Dp[2]=2;
    Dp[3]=4;
    for(int i=4;i<Dp.size();++i)
    {
        Dp[i]=Dp[i-3]+Dp[i-2]+Dp[i-1];
    }
    for(int i=0;i<T;++i)
    {
        cout<<Dp[V[i]]<<"\n";
    }
}