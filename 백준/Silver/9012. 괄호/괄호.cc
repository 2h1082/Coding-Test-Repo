#include "bits/stdc++.h"
using namespace std;

bool bIsMatch(const string& S)
{
    stack<char> St;
    for(auto& c : S)
    {
        if(c==')')
        {
            if(St.empty()) return false;
            St.pop();
        }
        else if(c=='(')    St.push(c);
    }
    return St.empty();
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    
    int N;
    cin>>N;
    
    while(N--)
    {
        string S;
        cin>>S;
        
        if(bIsMatch(S)) cout<<"YES\n";
        else            cout<<"NO\n";
    }
}