#include "bits/stdc++.h"
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    
    int N;
    cin>>N;
    vector<string> A(N);
    for(auto& a : A) cin>>a;
    sort(A.begin(),A.end(),[](const auto& a, const auto& b){
        if(a.length() != b.length()) return a.length() < b.length();
        return a < b;
    });
    A.erase(unique(A.begin(),A.end()),A.end());
    for(auto& a : A) cout<<a<<'\n';
}