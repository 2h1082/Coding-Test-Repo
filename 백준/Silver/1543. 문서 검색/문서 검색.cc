#include "bits/stdc++.h"
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    
    string T, S;
    getline(cin,T);
    getline(cin,S);
    int M=T.length(), N=S.length(), Idx=0, Cnt=0;
    for(int i=0;i<=M-N;)
    {
        if(T.substr(i,N)==S)
        {
            ++Cnt;
            i+=N;
        }
        else
        {
            ++i;
        }
    }
    cout<<Cnt;
}