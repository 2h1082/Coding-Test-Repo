#include "bits/stdc++.h"
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    int N,S,P;
    cin>>N>>S>>P;
    
    int Rank=1;
    
    vector<int> Score(N);
    for(auto& s : Score) cin>>s;

    int LastIdx=-1;
    for(int i=0;i<N;++i)
    {
        if(Score[i]>S) Rank++;
        else if (Score[i]==S) LastIdx=i;
        else break;
    }
    
    if (LastIdx+2>P || Rank>P) cout<<"-1";
    else                       cout<<Rank;
}