#include "bits/stdc++.h"
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    
    string S;
    cin>>S;
    vector<string> A;
    for(int i=0;i<S.length();++i)
    {
        A.push_back(S.substr(i));
    }
    sort(A.begin(),A.end());
    for(auto& a : A) cout<<a<<'\n';
}