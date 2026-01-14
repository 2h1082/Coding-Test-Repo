#include "bits/stdc++.h"
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    
    int N;
    cin>>N;
        
    vector<int> A(N,0);
    vector<string> Ans;
    
    for(auto& a : A) cin>>a;
    
    int Idx=0, Cur=1;
    stack<int> St;
    while(Idx<N)
    {
        if(!St.empty())
        {
            if(St.top()==A[Idx])
            {
                St.pop();
                Ans.push_back("-");
                ++Idx;
            }
            else if(St.top()<A[Idx])
            {
                St.push(Cur++);
                Ans.push_back("+");
            }
            else 
            {
                break;
            }
        }
        else
        {
            St.push(Cur++);
            Ans.push_back("+");
        }
    }
    if(!St.empty())
    {
        Ans.clear();
        Ans.push_back("NO");
    }
    for(auto& a : Ans) cout<<a<<'\n';
}