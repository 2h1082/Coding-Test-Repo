#include "bits/stdc++.h"
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    
    vector<int> Cnt(10,0);
    string S;
    cin>>S;
    
    int Max=0;
    for(auto& c : S) 
    {
        int Idx=c-'0';
        Cnt[Idx]++;
        
        int Cur=Cnt[Idx];
        if(Idx==6 || Idx==9) Cur=(Cnt[6]+Cnt[9]+1)/2;
        Max=max(Max,Cur);
    }
    cout<<Max;
}