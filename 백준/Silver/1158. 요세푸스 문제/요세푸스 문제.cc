#include "bits/stdc++.h"
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    
    int N,K;
    cin>>N>>K;
    
    vector<int> Num(N,0);
    iota(Num.begin(),Num.end(),1);
    
    cout<<'<';
    int Cur=0;
    for(int i=0;i<N;++i)
    {
        int Size=Num.size();
        int Idx=(Cur+K-1)%Size;
        cout<<Num[Idx];
        if(i!=N-1) cout<<", ";
        
        Num.erase(Num.begin()+Idx);
        if(Num.size()==Idx) Cur=0;
        else                Cur=Idx;
    }
    cout<<'>';
}