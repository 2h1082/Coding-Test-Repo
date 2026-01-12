#include "bits/stdc++.h"
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    
    int T;
    cin>>T;
    
    while(T--)
    {
        string L,R,S;
        cin>>S;
        
        for(auto& c : S)
        {
            if(c=='<')
            {
                if(L.empty()) continue;
                R+=L.back();
                L.pop_back();
            }
            else if(c=='>')
            {
                if(R.empty()) continue;
                L+=R.back();
                R.pop_back();
            }
            else if(c=='-')
            {
                if(L.empty()) continue;
                L.pop_back();
            }
            else
            {
                L.push_back(c);
            }
        }
        cout<<L;
        for(auto It=R.rbegin();It!=R.rend();++It) cout<<*It;
        cout<<'\n';
    }
}