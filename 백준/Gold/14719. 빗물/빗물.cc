#include "bits/stdc++.h"
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    int H,W;
    cin>>H>>W;
    
    vector<int> Height(W,0), L(W,0), R(W,0);
    for(int i=0;i<W;++i)
    {
        cin>>Height[i];
    }
    L[0]=Height[0];
    R[W-1]=Height[W-1];
    for(int i=1;i<W;++i)    L[i]=max(L[i-1],Height[i]);
    for(int i=W-2;i>=0;--i) R[i]=max(R[i+1],Height[i]);
    
    int Ans=0;
    for(int i=1;i<W-1;++i)
    {
        Ans+=min(L[i],R[i])-Height[i];
    }
    cout<<Ans;
}