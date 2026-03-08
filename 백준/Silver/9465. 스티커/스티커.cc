#include "bits/stdc++.h"
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    
    int T;
    cin>>T;
    while(T--)
    {
        int N;
        cin>>N;
        vector<vector<int>> A(2,vector<int>(N,0)), Dp(2,vector<int>(N,0));
        for(auto& r : A)
        {
            for(auto& c : r) cin>>c;
        }
        Dp[0][0]=A[0][0];
        Dp[1][0]=A[1][0];
        int Ans=max(Dp[0][0],Dp[1][0]);
        if(N>1)
        {
            Dp[0][1]=A[1][0]+A[0][1];
            Dp[1][1]=A[0][0]+A[1][1];
            Ans=max(Dp[0][1],Dp[1][1]);
        }
        for(int i=2;i<N;++i)
        {
            for(int j=0;j<2;++j)
            {
                // 첫번째 전 스티커는 무조건 대각
                // 두번째 전 스티커도 같은 행은 어차피 첫번째 전 대각 스티커를 포함시켜야 이득이니 대각만 고려
                // -> 음수가 없기 때문
                Dp[j][i]=max(Dp[(j+1)%2][i-1],Dp[(j+1)%2][i-2])+A[j][i];
                Ans=max(Dp[j][i],Ans);
            }
        }
        cout<<Ans<<'\n';
    }
}