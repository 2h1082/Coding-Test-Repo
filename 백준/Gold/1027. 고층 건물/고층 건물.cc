#include "bits/stdc++.h"
using namespace std;
using ll=long long;
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    int N;
    cin>>N;
    vector<ll> B(N,0);
    for(auto& b : B) cin>>b;
    
    int Ans=0;
    for(int i=0;i<N;++i)
    {
        int Cnt=0;
        
        ll Num=LLONG_MAX, Den1=1;
        for(int j=i-1;j>=0;--j)
        {
            ll Numer=B[i]-B[j], Den2=i-j;
            if(Numer*Den1 < Num*Den2)
            {
                Num=Numer;
                Den1=Den2;
                Cnt++;
            }
        }
        Num=LLONG_MIN;
        Den1=1;
        for(int j=i+1;j<N;++j)
        {
            ll Numer=B[j]-B[i], Den2=j-i;
            if(Numer*Den1 > Num*Den2)
            {
                Num=Numer;
                Den1=Den2;
                Cnt++;
            }
        }
        Ans=max(Ans,Cnt);
    }
    cout<<Ans;
}