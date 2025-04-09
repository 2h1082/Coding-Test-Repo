#include <iostream>
#include <vector>
#include <functional>
using namespace std;
int main()
{
    int N=0;
    cin>>N;
    vector<int> health(N,0);
    vector<int> pleasure(N,0);
    
    for(int i=0;i<N;i++)
    {
        cin>>health[i];
    }
    for(int i=0;i<N;i++)
    {
        cin>>pleasure[i];
    }
    vector<int> dp(100,0);
    for(int i=0;i<N;i++)
    {
        for(int j=99;j>=health[i];j--)
        {
            dp[j]=max(dp[j],dp[j-health[i]]+pleasure[i]);
        }
    }
    int Max=0;
    for(int i=0;i<100;i++) Max=max(dp[i],Max);
    cout<<Max;
    return 0;
}