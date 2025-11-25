#include "bits/stdc++.h"
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    
    string In;
    cin>>In;
    
    transform(In.begin(),In.end(),In.begin(),[](unsigned char c){
        return toupper(c);
    });
    
    int Cnt[26]={0};
    int Max=0, MaxCnt=0, MaxIdx=0;
    for(const auto& c : In)
    {
        Cnt[c-'A']++;
        if(Max < Cnt[c-'A'])  
        {
            Max=Cnt[c-'A'];
            MaxIdx=c-'A';
            MaxCnt=1;
        }
        else if(Max==Cnt[c-'A']) 
        {
            MaxCnt++;
        }
    }
    char c = 'A'+MaxIdx;
    if(MaxCnt>1) cout<<"?";
    else         cout<<c;
    
}