#include <bits/stdc++.h>

using namespace std;
using ll=long long;

int Mod=1000000007;
ll Pow(ll Num, int P)
{
    if(P==0) return 1;
    if(P==1)
    {
        return Num%Mod;
    }
    ll Res=Pow(Num,P/2);
    Res=(Res*Res)%Mod;
    if(P%2)
    {
        return Res*Num%Mod;
    }
    else
    {
        return Res;
    }
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int N=0;
    cin>>N;
    vector<ll> Num(N,0);
    for(auto& n : Num)
    {
        cin>>n;
    }
    sort(Num.begin(),Num.end());
    ll Ans=0;
    for(int i=0;i<N;++i)
    {
        ll Add=(Pow(2,i)-Pow(2,N-i-1)+Mod)%Mod;
        Ans=(Ans+(Num[i]*Add)%Mod)%Mod;
    }
    cout<<Ans;
}