#include "bits/stdc++.h"
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    
    int N;
    cin>>N;
    vector<int> A(N);
    for(auto& a : A) cin>>a;
    sort(A.begin(),A.end(),greater<>());
    
    int Ans=0;
    for(int i=0;i<N;++i)
    {
        Ans=max({Ans,A[i],A[i]*(i+1)});
    }
    cout<<Ans;
}