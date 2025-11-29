#include "bits/stdc++.h"
using namespace std;
    
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    int N,M;
    cin>>N>>M;
    vector<int> Loc(M);
    for(int i=0;i<M;++i)
    {
        cin>>Loc[i];
    }

    int Ans=Loc[0];
    for(int i=1;i<M;++i)
    {
        Ans=max(Ans,(Loc[i]-Loc[i-1]+1)/2);
    }
    Ans=max(Ans,N-Loc[M-1]);

    cout<<Ans;
}