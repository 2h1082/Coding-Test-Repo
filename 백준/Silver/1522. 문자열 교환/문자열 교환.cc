#include "bits/stdc++.h"
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    string S;
    cin>>S;
    
    int ACnt=0, N=S.size();
    for(auto& c : S)
    {
        if(c=='a') ACnt++;
    }
    
    if(ACnt==0 || ACnt==N)
    {
        cout<<0;
        return 0;
    }
    
    int BCnt=0, Ans=0;
    for(int i=0;i<ACnt;++i)
    {
        if(S[i]=='b') BCnt++;
    }
    Ans=BCnt;
    
    for(int i=1;i<N;++i)
    {
        if(S[i-1]=='b')      BCnt--;
        if(S[(i+ACnt-1)%N]=='b') BCnt++;
        
        Ans=max(0,min(Ans,BCnt));
    }
    cout<<Ans;
}