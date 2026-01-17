#include "bits/stdc++.h"
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    
    string S;
    cin>>S;
    
    stack<char> St;
    int Cnt=0;
    for(int i=0;i<S.length();++i)
    {
        if(S[i]=='(')                       St.push(S[i]);
        else if(S[i]==')' && !St.empty())
        {
            St.pop();
            if(S[i-1]=='(')    Cnt+=St.size();
            else               ++Cnt;
        }
    }
    cout<<Cnt;
}