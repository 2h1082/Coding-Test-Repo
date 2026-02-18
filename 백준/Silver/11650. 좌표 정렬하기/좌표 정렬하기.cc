#include "bits/stdc++.h"
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    
    int N;
    cin>>N;
    vector<pair<int,int>> A(N);
    for(auto& [x,y]:A) cin>>x>>y;
    sort(A.begin(),A.end());
    for(auto& [x,y]:A) cout<<x<<' '<<y<<'\n';
}