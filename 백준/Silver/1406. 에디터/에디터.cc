#include "bits/stdc++.h"
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    string L, R;
    cin>>L;
    
    int M;
    cin>>M;
    while(M--)
    {
        char Com;
        cin>>Com;
        
        if(Com=='L')
        {
            if(!L.empty()) 
            {
                R+=L.back();
                L.pop_back();
            }
        }
        else if(Com=='D')
        {
            if(!R.empty()) 
            {
                L+=R.back();
                R.pop_back();
            }
        }
        else if(Com=='B')
        {
            if(!L.empty())
            {
                L.pop_back();
            }
        }
        else if(Com=='P')
        {
            char Add;
            cin>>Add;
            
            L+=Add;
        }
    }
    cout<<L;
    for(auto It=R.rbegin();It!=R.rend();++It) cout<<*It;
}