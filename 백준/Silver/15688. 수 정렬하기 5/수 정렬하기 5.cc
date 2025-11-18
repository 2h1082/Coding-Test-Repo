#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    
    int N=0;
    cin>>N;
    vector<int> Num(N,0);
    for(auto& n : Num) cin>>n;
    sort(Num.begin(),Num.end());
    for(auto& n : Num) cout<<n<<'\n';
}