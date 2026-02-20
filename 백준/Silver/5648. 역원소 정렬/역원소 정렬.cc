#include "bits/stdc++.h"
using namespace std;
using ll=long long;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    
    int N;
    cin>>N;
    vector<ll> A(N);
    for(auto& a : A)
    {
        string Num;
        cin>>Num;
        reverse(Num.begin(),Num.end());
        a=stoll(Num);
    }
    sort(A.begin(),A.end());
    for(auto& a : A) cout<<a<<'\n';
}