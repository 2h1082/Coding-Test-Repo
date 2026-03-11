#include "bits/stdc++.h"
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    
    int N,K;
    cin>>N>>K;
    
    vector<int> A(N,0);
    for(auto& a : A) cin>>a;
    
    int Ans=0;
    for(int i=N-1;i>=0;--i)
    {
        Ans+=K/A[i];
        K%=A[i];
    }
    cout<<Ans;
}