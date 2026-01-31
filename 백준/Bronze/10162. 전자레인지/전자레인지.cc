#include "bits/stdc++.h"
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    
    int T;
    cin>>T;
    
    int A[]={300,60,10};
    int Ans[]={0,0,0};
    for(int i=0;i<3;++i)
    {
        Ans[i]=T/A[i];
        T%=A[i];
    }
    if(T) 
    {
        cout<<-1;
        return 0;
    }
    for(auto& a : Ans) cout<<a<<' ';
    
}