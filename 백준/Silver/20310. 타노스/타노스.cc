#include "bits/stdc++.h"
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    string S;
    cin>>S;
    
    int Z=0, O=0;
    for(char c : S)
    {
        if(c=='1') ++O;
        else       ++Z;
    }
    string Ans;
    vector<bool> Removed(S.size(),false);
    
    int Remove0=Z/2, Remove1=O/2;
    
    for(int i=S.size()-1;i>=0;--i)
    {
        if(S[i]=='0' && Remove0>0)
        {
            Removed[i]=true;
            Remove0--;
        }
    }
    for(int i=0;i<S.size();++i)
    {
        if(S[i]=='1' && Remove1>0)
        {
            Removed[i]=true;
            Remove1--;
        }
    }
    for(int i=0;i<S.size();++i) 
    {
        if(Removed[i]) continue;
        Ans+=S[i];
    }
    cout<<Ans;
}