#include "bits/stdc++.h"
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    
    int N;
    cin>>N;
    
    while(N--)
    {
        string S1, S2;
        cin>>S1>>S2;
        
        if(S1==S2) 
        {
            cout<<"Possible\n";
            continue;
        }
        else if(S1.length()!=S2.length()) 
        {
            cout<<"Impossible\n";
            continue;
        }
        
        vector<int> Cnt(26,0);
        for(int i=0;i<S1.size();++i) 
        {
            Cnt[S1[i]-'a']++;
            Cnt[S2[i]-'a']--;
        }
        bool bIsEnd=false;
        for(int i=0;i<26;++i)
        {
            if(Cnt[i])
            {
                cout<<"Impossible\n";
                bIsEnd=true;
                break;
            }
        }
        if(!bIsEnd) cout<<"Possible\n";
    }
}