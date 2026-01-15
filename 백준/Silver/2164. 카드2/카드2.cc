#include "bits/stdc++.h"
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    
    int N;
    cin>>N;
    
    queue<int> Q;
    for(int i=1;i<=N;++i) Q.push(i);
    while(Q.size()!=1)
    {
        Q.pop();
        Q.push(Q.front());
        Q.pop();
    }
    cout<<Q.front();
}