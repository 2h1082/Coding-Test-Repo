#include "bits/stdc++.h"
using namespace std;
using ll=long long;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    
    int N;
    cin>>N;
    map<ll, int> Cnt;
    int Max=0;
    ll Ans=0;
    while(N--)
    {
        ll Num;
        cin>>Num;
        ++Cnt[Num];
        if(Max < Cnt[Num] || (Max==Cnt[Num] && Ans > Num))
        {
            Ans=Num;
            Max=Cnt[Num];
        }
    }
    cout<<Ans;
}