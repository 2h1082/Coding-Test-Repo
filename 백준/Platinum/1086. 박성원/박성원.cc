#include <bits/stdc++.h>

using namespace std;
using ll=long long;

int main()
{
    int N=0,K=0;
    cin>>N;
    vector<string> Nums(N);
    for(auto& n : Nums)
    {
        cin>>n;
    }
    cin>>K;
    
    vector<int> Mod(N,0), Len(N,0);
    for(int i=0;i<N;++i)
    {
        Len[i]=Nums[i].size();
        int Val=0;
        for(char c : Nums[i])
        {
            Val=(Val*10+(c-'0'))%K;
        }
        Mod[i]=Val;
    }
    vector<int> Pow10(51);
    Pow10[0]=1;
    for(int i=1;i<=50;++i)
    {
        Pow10[i]=(Pow10[i-1]*10)%K;
    }
    int MaxBits=1<<N;
    vector<vector<ll>> DP(MaxBits,vector<ll>(K,0));
    DP[0][0]=1;
    for(int Mask=0;Mask<MaxBits;++Mask)
    {
        for(int r=0;r<K;++r)
        {
            if(DP[Mask][r]==0) continue;
            
            for(int Nxt=0;Nxt<N;++Nxt)
            {
                if(Mask&(1<<Nxt)) continue;
                int NxtMask=Mask|(1<<Nxt);
                int NxtR=(r*Pow10[Len[Nxt]]+Mod[Nxt])%K;
                DP[NxtMask][NxtR]+=DP[Mask][r];
            }
        }
    }
    ll Numerator=DP[(1<<N)-1][0];
    ll Denominator=1;
    for(int i=2;i<=N;++i)
    {
        Denominator*=i;
    }
    ll Res=gcd(Numerator,Denominator);
    
    cout<<Numerator/Res<<"/"<<Denominator/Res;
}