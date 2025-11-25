#include "bits/stdc++.h"
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    
    int N=0;
    cin>>N;
    vector<string> C(N);
    int Idx1, Idx2;
    for(int i=0;i<N;++i) 
    {
        cin>>C[i];
        if(C[i]=="KBS1")      Idx1=i;
        else if(C[i]=="KBS2") Idx2=i;
    }
    string Ans;
    for(int i=0;i<Idx1;++i) Ans+='1';
    for(int i=0;i<Idx1;++i) Ans+='4';
    
    if(Idx1>Idx2) Idx2++;
    
    for(int i=0;i<Idx2;++i) Ans+='1';
    for(int i=0;i<Idx2-1;++i) Ans+='4';
    
    cout<<Ans;
}