#include "bits/stdc++.h"
using namespace std;
using ll=long long; 
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    int N;
    cin>>N;
    
    vector<int> Cost(N), Weight(N-1);
    for(auto& w : Weight) cin>>w;
    for(auto& c : Cost)   cin>>c;
    
    ll CurCost=Cost[0];
    ll Ans=0;
    for(int i=0;i<N-1;++i)
    {
        if(Cost[i]<CurCost) CurCost=Cost[i];
        Ans+=CurCost*Weight[i];
    }
    cout<<Ans;
}