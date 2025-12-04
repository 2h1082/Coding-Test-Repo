#include "bits/stdc++.h"
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    int N;
    cin>>N;
    
    vector<int> Order(N,0), Ans;
    for(auto& n : Order) cin>>n;
    
    for(int i=N-1;i>=0;--i)
    {
        Ans.insert(Ans.begin()+Order[i],i+1);
    }
    for(auto& n : Ans) cout<<n<<' ';
}
