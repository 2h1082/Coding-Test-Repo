#include "bits/stdc++.h"
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    
    int N;
    cin>>N;
    vector<pair<int,int>> A(N);
    for(auto& [e,s] : A) cin>>s>>e;
    sort(A.begin(),A.end());
    
    int Cnt=0, Cur=0;
    for(auto& [e,s] : A)
    {
        if(Cur<=s)
        {
            Cur=e;
            ++Cnt;
        }
    }
    cout<<Cnt;
}