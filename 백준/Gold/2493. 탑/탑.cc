#include "bits/stdc++.h"
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    
    int N;
    cin>>N;
    
    stack<int> St;
    vector<int> H(N,0), Ans(N,0);
    for(int i=0;i<N;++i)
    {
        cin>>H[i];
        
        while(!St.empty() && H[St.top()] < H[i]) St.pop();
        if(!St.empty()) Ans[i]=St.top()+1;
        St.push(i);
    }
    for(auto& a : Ans) cout<<a<<' ';
}