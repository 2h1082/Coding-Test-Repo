#include "bits/stdc++.h"
using namespace std;

int main()
{
    int n=0;
    cin>>n;
    int Cnt=INT_MAX;
    for(int i=0;5*i<=n;++i)
    {
        int Cur=n-(5*i), Temp=0;
        if(Cur%2==0)
        {
            Temp=Cur/2;
            Cnt=min(Cnt,Temp+i);
        }
    }
    cout<<(Cnt==INT_MAX ? -1 : Cnt);
}