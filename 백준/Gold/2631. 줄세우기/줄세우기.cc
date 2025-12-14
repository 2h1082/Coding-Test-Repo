#include "bits/stdc++.h"
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    int N;
    cin>>N;
    
    vector<int> Order(N,0);
    for(auto& o : Order) cin>>o;
    
    vector<int> LIS;
    for(int i=0;i<N;++i)
    {
        if(LIS.empty() || Order[i] > LIS.back())
        {
            LIS.push_back(Order[i]);
        }
        else
        {
            auto Lower=lower_bound(LIS.begin(),LIS.end(),Order[i]);
            *Lower=Order[i];
        }
    }
    
    cout<<N-(int)LIS.size();
}