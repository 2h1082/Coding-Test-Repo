#include "bits/stdc++.h"
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    
    int N;
    cin>>N;
    vector<int> A(N,0);
    for(auto& a : A) cin>>a;
    sort(A.begin(),A.end());
    
    int Max=0;
    for(int i=0;i<N;++i)
    {
        Max=max(Max,A[i]*(N-i));
    }
    cout<<Max;
}