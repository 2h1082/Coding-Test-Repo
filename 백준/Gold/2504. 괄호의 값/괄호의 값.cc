#include "bits/stdc++.h"
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    
    string S;
    cin>>S;
    
    int Total=0, Part=1;
    stack<char> St;
    for(int i=0;i<S.length();++i)
    {
        if(S[i]=='(')
        {
            Part*=2;
            St.push(S[i]);
        }
        else if (S[i]=='[')
        {
            Part*=3;
            St.push(S[i]);
        }
        else if(!St.empty())
        {
            if(S[i]==')' && St.top()=='(')
            {
                if (S[i-1]=='(') Total+=Part;
                St.pop();
                Part/=2;
            }
            else if(S[i]==']' && St.top()=='[')
            {
                if (S[i-1]=='[') Total+=Part;
                St.pop();
                Part/=3;
            }
            else
            {
                Total=0;
                break;
            }
        }
        else
        {
            Total=0;
            break;
        }
    }
    if(!St.empty()) Total=0;
    cout<<Total;
}