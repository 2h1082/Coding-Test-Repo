#include "bits/stdc++.h"
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    
    int N;
    cin>>N;
    vector<int> A(N);
    for(auto& a : A) cin>>a;
    sort(A.begin(),A.end(),greater<>());
    for(auto& a : A) cout<<a<<'\n';
}