#include "bits/stdc++.h"
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    
    int N;
    string L,R;
    cin>>L>>N;
    
    while(N--)
    {
        char Op;
        cin>>Op;
        
        if(Op=='L' && !L.empty())
        {
            R+=L.back();
            L.pop_back();
        }
        else if(Op=='D' && !R.empty())
        {
            L+=R.back();
            R.pop_back();
        }
        else if(Op=='B' && !L.empty())
        {
            L.pop_back();
        }
        else if(Op=='P')
        {
            char C;
            cin>>C;
            L+=C;
        }
    }
    cout<<L;
    for(auto It=R.rbegin();It!=R.rend();++It) cout<<*It;
}