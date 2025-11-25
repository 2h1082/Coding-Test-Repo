#include "bits/stdc++.h"
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    
    int H,W,N,M;
    cin>>H>>W>>N>>M;
    N++;
    M++;
    int Ans=((H+N-1)/N) * ((W+M-1)/M);
    cout<<Ans;
}