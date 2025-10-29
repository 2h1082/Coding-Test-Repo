#include <bits/stdc++.h>

using namespace std;
using ll=long long;
int main()
{
    ll n=0;
    cin>>n;
    
    ll ans=n;
    for(ll i=2;i*i<=n;++i)
    {
        if(n%i==0) 
        {
            while(n%i==0) n/=i;
            ans-=ans/i;
        }
    }
    if(n>1) ans-=ans/n;
    cout<<ans;
}