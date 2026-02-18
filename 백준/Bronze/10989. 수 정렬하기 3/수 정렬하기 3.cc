#include "bits/stdc++.h"
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    
    int N;
    cin>>N;
    vector<int> A(10001,0);
    for(int i=0;i<N;++i)
    {
        int Num;
        cin>>Num;
        ++A[Num];
    }
    for(int i=1;i<10001;++i) 
    {
        if(!A[i]) continue;
        for(int j=0;j<A[i];++j) cout<<i<<'\n';
    }
}