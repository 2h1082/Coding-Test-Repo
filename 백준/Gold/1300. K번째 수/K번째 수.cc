#include <bits/stdc++.h>

using namespace std;
using ll=long long;
ll N=0, k=0;
bool Count(ll Num)
{
    ll s=0;
    for(ll i=1;i<=N;++i)
    {
        s+=min(Num/i,N);
        if(s>=k) return true;
    }
    return false;
}

int main()
{
    cin>>N>>k;
    
    ll l=1, r=LLONG_MAX;
    while(l<r)
    {
        ll m=l+(r-l)/2;
        if(Count(m)) r=m;
        else         l=m+1;
    }
    cout<<l;
}