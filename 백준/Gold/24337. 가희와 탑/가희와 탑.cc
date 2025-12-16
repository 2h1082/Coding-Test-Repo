#include "bits/stdc++.h"
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    int N, a, b;
    cin>>N>>a>>b;
    
    if(a+b-1 > N) 
    {
        cout<<-1;
        return 0;
    }
    
    int Max=max(a,b);    
    vector<int> A;
    
    for(int i=1;i<a;++i) A.push_back(i);
    A.push_back(Max);
    for(int i=b-1;i>=1;--i) A.push_back(i);        
    
    while(A.size() < N) A.insert(A.begin()+1,1);
    
    for(auto& ans : A) cout<<ans<<' ';
}