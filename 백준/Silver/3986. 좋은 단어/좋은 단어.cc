#include "bits/stdc++.h"
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    
    int N;
    cin>>N;
    
    int Cnt=0;
    while(N--)
    {
        string S;
        cin>>S;
        
        stack<char> St;
        bool bIsGood=true;
        for(auto& c : S)
        {
            if (St.empty() || St.top()!=c)      St.push(c);
            else if(!St.empty() && St.top()==c) St.pop();
            else                 
            {
                bIsGood=false;
                break;
            }
        }
        if(bIsGood && St.empty())  ++Cnt;
    }
    cout<<Cnt;
}