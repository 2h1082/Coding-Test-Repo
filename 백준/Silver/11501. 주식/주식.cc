#include "bits/stdc++.h"
using namespace std;
using ll=long long;
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    int T;
    cin>>T;
    
    while(T--)
    {
        int N;
        cin>>N;
        
        vector<int> P(N);
        for (auto& p : P) cin>>p;

        ll Total=0;
        int Max=0;
        
        for (int i=N-1;i>=0;--i)
        {
            if (P[i]>Max) Max=P[i];
            else          Total+=Max-P[i];
        }

        cout<<Total<<'\n';
    }
}