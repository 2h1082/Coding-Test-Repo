#include <bits/stdc++.h>

using namespace std;
using ll=long long;

ll CountOnes(ll N)
{
    if(N<=0) return 0;
    
    ll Res=0;
    for(ll Bits=0;Bits<63;++Bits)
    {
        ll Cycles= 1LL<<(Bits+1);
        ll HalfCycles= 1LL<<(Bits);
        ll FullCount=(N+1)/Cycles;
        ll RemainCount=(N+1)%Cycles;
        Res+=FullCount*(HalfCycles);
        Res+= RemainCount>HalfCycles ? RemainCount-HalfCycles : 0;
    }
    return Res;
}

int main()
{
    ll A,B;
    cin>>A>>B;
    
    cout<<CountOnes(B)-CountOnes(A-1);
}
