#include "bits/stdc++.h"
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    
    int N,K;
    cin>>N>>K;
    vector<int> A(N,0);
    for(int i=N-1;i>=0;--i) cin>>A[i];
    int Cnt=0;
    for(int i=0;i<N;++i)
    {
        Cnt+=K/A[i];
        K%=A[i];
    }
    cout<<Cnt;
}