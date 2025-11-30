#include "bits/stdc++.h"
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    int N,X;
    cin>>N>>X;
    
    vector<int> Num(N,0);
    for(auto& n : Num) cin>>n;
    
    int Sum=0;
    for(int i=0;i<X;++i) Sum+=Num[i];
    
    int Cnt=1, Max=Sum;
    for(int i=X;i<N;++i)
    {
        Sum+=Num[i] - Num[i-X];
        if(Sum > Max)
        {
            Cnt=1;
            Max=Sum;
        }
        else if(Sum==Max)
        {
            ++Cnt;
        }
    }
    if(Max==0)
    {
        cout<<"SAD\n";
    }
    else
    {
        cout<<Max<<'\n'<<Cnt;
    }
}