#include "bits/stdc++.h"
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    
    string S1,S2;
    cin>>S1>>S2;
    
    vector<int> Cnt(26,0);
    for(auto& c : S1) Cnt[c-'a']++;
    for(auto& c : S2) Cnt[c-'a']--;
    
    int Ans=0;
    for(int i=0;i<26;++i)
    {
        Ans+=abs(Cnt[i]);
    }
    cout<<Ans;
}