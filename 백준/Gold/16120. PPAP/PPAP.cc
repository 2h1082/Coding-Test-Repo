#include "bits/stdc++.h"
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    
    string S;
    cin>>S;
    
    string St;
    for(auto& c : S)
    {        
        St+=c;
        while(St.size() >=4)
        {
            int N=St.size();
            if(St[N-4]=='P' && St[N-3]=='P' && St[N-2]=='A' && St[N-1]=='P')
            {
                St.pop_back();
                St.pop_back();
                St.pop_back();
                St.pop_back();
                St+='P';
            }
            else break;
        }
    }
    if(St=="P") cout<<"PPAP";
    else        cout<<"NP";
}