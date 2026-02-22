#include "bits/stdc++.h"
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    
    int T;
    cin>>T;
    while(T--)
    {
        int N,M;
        cin>>N>>M;
        vector<int> A(N), B(M);
        for(auto& a : A) cin>>a;
        for(auto& b : B) cin>>b;
        sort(A.begin(),A.end());
        sort(B.begin(),B.end());
        
        int Rb=M-1, Ans=0;
        for(int i=N-1;i>=0;--i)
        {
            while(Rb>=0 && A[i]<=B[Rb]) --Rb;
            Ans+=Rb+1;
        }
        cout<<Ans<<'\n';
    }
}