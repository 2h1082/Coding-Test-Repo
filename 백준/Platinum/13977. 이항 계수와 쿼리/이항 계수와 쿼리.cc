#include <bits/stdc++.h>

using namespace std;
using ll=long long;
const int Max=4000000;
const int Mod=1000000007;
vector<ll> Fact(Max+1), InvFact(Max+1);

ll ModPow(ll a, ll b)
{
    ll Res=1;
    while(b>0)
    {
        if(b&1) Res=Res*a%Mod;
        a=a*a%Mod;
        b>>=1;
    }
    return Res;
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    Fact[0]=1;
    for(int i=1;i<=Max;++i)
    {
        Fact[i]=Fact[i-1]*i%Mod;
    }
    InvFact[Max]=ModPow(Fact[Max],Mod-2);
    for(int i=Max;i>0;--i)
    {
        InvFact[i-1]=InvFact[i]*i%Mod;
    }
    int M=0,N=0,K=0;
    cin>>M;
    while(M--)
    {
        int Res=0;
        cin>>N>>K;
        if(K<0 || K>N)
        {
            cout<<Res<<"\n";
            continue;
        }
        Res=Fact[N]*InvFact[K]%Mod*InvFact[N-K]%Mod;
        cout<<Res<<"\n";
    }
    
}