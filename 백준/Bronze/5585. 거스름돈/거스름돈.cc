#include "bits/stdc++.h"
using namespace std;

int main()
{
    int Coin[6]={500,100,50,10,5,1};
    int Num=0;
    cin>>Num;
    int Remain=1000-Num;
    long long Res=0;
    for(auto& c : Coin)
    {
        if(c>Remain) continue;
        long long Cnt=Remain/c;
        Res+=Cnt;
        Remain%=c;
    }
    cout<<Res;
}