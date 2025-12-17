#include "bits/stdc++.h"
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    for(int T=0;T<3;++T)
    {
        int N;
        cin>>N;
        
        vector<pair<int,int>> Coin(N);
        int Total=0;
        for(auto& [V,Cnt] : Coin)
        {
            cin>>V>>Cnt;
            Total+=V*Cnt;
        }
        if(Total%2) 
        {
            cout<<0<<'\n';
            continue;
        }
        
        int Target=Total/2;
        vector<bool> Dp(Target+1,false);
        Dp[0]=true;
        
        for(auto [V, Cnt] : Coin)
        {
            vector<int> Used(Target+1,-1);
            
            for(int i=0;i<=Target;++i)
            {
                if(Dp[i]) Used[i]=0;
            }
            for(int i=0;i<=Target;++i)
            {
                if(Used[i]>=0 && Used[i]<Cnt && i+V<=Target && Used[i+V]==-1)
                {
                    Dp[i+V]=true;
                    Used[i+V]=Used[i]+1;
                }
            }
        }
        cout<<(Dp[Target] ? 1 : 0)<<'\n';
    }
}