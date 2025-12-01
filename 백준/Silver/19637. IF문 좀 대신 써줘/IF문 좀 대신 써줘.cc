#include "bits/stdc++.h"
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    int N,M;
    cin>>N>>M;
    
    vector<string> Name(N);
    vector<int> Max(N);
    for(int i=0;i<N;++i)  cin>>Name[i]>>Max[i];
    
    while(M--)
    {
        int Cur;
        cin>>Cur;
        auto It=lower_bound(Max.begin(),Max.end(),Cur);
        int Idx=It-Max.begin();
        cout<<Name[Idx]<<'\n';
    }
}