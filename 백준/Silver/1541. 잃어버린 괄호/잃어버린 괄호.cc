#include "bits/stdc++.h"
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    
    string In;
    cin>>In;
    
    stringstream ss(In);
    int Num=0, Sum=0;
    char Op;
    bool bIsMinus=false;
    ss>>Sum;
    while(ss>>Op>>Num)
    {
        if(Op=='-')  bIsMinus=true;
        if(bIsMinus) Sum-=Num;
        else         Sum+=Num;
    }
    cout<<Sum;
}