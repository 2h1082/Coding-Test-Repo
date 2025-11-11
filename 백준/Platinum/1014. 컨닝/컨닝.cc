#include <bits/stdc++.h>
using namespace std;
using ll=long long;
int N,M;
vector<string> Map;
int Count(int x)
{
    return __builtin_popcount(x);
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    
    int C;
    cin>>C;
    while(C--)
    {
        cin>>N>>M;
        Map.assign(N,"");
        for(auto& m : Map) cin>>m;
        
        // 착석 불가 자리 비트 마스크 형태로 행단위 표시
        vector<int> Blocked(N,0);
        for(int i=0;i<N;++i)
        {
            for(int j=0;j<M;++j)
            {
                if(Map[i][j]=='x') Blocked[i]|=(1<<j);
            }
        }
        // 행 단위로 가능한 착석 패턴 모두 찾아 저장
        vector<int> Valid;
        for(int Mask=0;Mask<(1<<M);++Mask)
        {
            if((Mask&(Mask<<1))==0) Valid.push_back(Mask);
        }
        
        vector<vector<int>> Dp(N,vector<int>(1<<M,0));
        // 첫행 막힌 자리 판별하여 가능한 패턴별 착석 테이블 할당
        for(int Mask:Valid)
        {
            if((Mask&Blocked[0])==0) Dp[0][Mask]=Count(Mask);
        }
        
        for(int i=1;i<N;++i)
        {
            for(int Mask:Valid)
            {
                // 막힌 자리 앉는 패턴 스킵
                if(Mask&Blocked[i]) continue; 
                for(int Prev : Valid)
                {
                    if(Prev&Blocked[i-1]) continue;
                    if((Mask&(Prev<<1)) || (Mask&(Prev>>1))) continue;
                    Dp[i][Mask]=max(Dp[i][Mask],Dp[i-1][Prev]+Count(Mask));
                }
            }
        }
        int Ans=0;
        for(int Mask:Valid) Ans=max(Ans,Dp[N-1][Mask]);
        cout<<Ans<<'\n';
    }
}