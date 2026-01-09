#include "bits/stdc++.h"
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    
    int A,B,C;
    cin>>A>>B>>C;
    
    int Ans=A*B*C;
    string S=to_string(Ans);
    
    vector<int> Cnt(10,0);
    for(auto& c : S) Cnt[c-'0']++;
    for(int& a : Cnt) cout<<a<<'\n';
}