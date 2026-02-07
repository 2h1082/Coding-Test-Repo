#include "bits/stdc++.h"
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    
    int N;
    cin>>N;
    vector<int> Plus, Minus;
    int Zeros=0;
    long long Sum=0;
    for(int i=0;i<N;++i)
    {
        int Num;
        cin>>Num;
        if(Num==1)     ++Sum;
        else if(Num>1) Plus.push_back(Num);
        else if(Num<0) Minus.push_back(Num);
        else           ++Zeros;
    }
    sort(Plus.begin(),Plus.end(),greater<>());
    sort(Minus.begin(),Minus.end());
    
    for(int i=0;i<Plus.size();i+=2)
    {
        if(i+1<Plus.size()) Sum+=Plus[i]*Plus[i+1];
        else                Sum+=Plus[i];
    }
    for(int i=0;i<Minus.size();i+=2)
    {
        if(i+1<Minus.size()) Sum+=Minus[i]*Minus[i+1];
        else if(Zeros<1)     Sum+=Minus[i];
    }
    cout<<Sum;
}