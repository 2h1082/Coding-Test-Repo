#include <iostream>
#include <vector>
#include <cmath>

using namespace std;
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int N=0, M=0;
    cin>>N>>M;
    vector<int> V(N);
    vector<int> Dp(N);
    for(int i=0;i<N;++i)
    {
        cin>>V[i];
        if(i>0) Dp[i]=Dp[i-1]+V[i];
        else    Dp[i]=V[i];
    }
    while(M--)
    {
        int i=0,j=0;
        cin>>i>>j;
        int Answer= i==1 ? Dp[j-1] : Dp[j-1]-Dp[i-2];
        cout<<Answer<<"\n";
    }
}