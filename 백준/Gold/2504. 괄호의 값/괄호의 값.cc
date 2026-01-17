#include "bits/stdc++.h"
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    
    string S;
    cin>>S;
    
    stack<char> St;
    int Mul=1, Ans=0;
    for(int i=0;i<S.length();i++)
    {
        if(S[i]=='(')
        {
            Mul*=2;
            St.push(S[i]);
        }
        else if(S[i]=='[')
        {
            Mul*=3;
            St.push(S[i]);
        }
        else if (S[i]==')')
        {
            if (St.empty() || St.top()!='(')
            {
                Ans=0;
                break;
            }
            if (S[i-1]=='(') Ans+=Mul;
            St.pop();
            Mul/=2;
        }
        else if (S[i]==']')
        {
            if (St.empty() || St.top()!='[')
            {
                Ans=0;
                break;
            }
            if (S[i-1]=='[') Ans+=Mul;
            St.pop();
            Mul/=3;
        }
    }
    if (!St.empty()) Ans=0;
    cout<<Ans;
}