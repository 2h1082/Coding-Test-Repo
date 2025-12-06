#include "bits/stdc++.h"
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    int N,D,K,C;
    cin>>N>>D>>K>>C;
    
    vector<int> Type(N), Cnt(D+1,0);
    for(auto& t : Type) cin>>t;
    
    
    int Max=0, Kinds=0;
    for(int i=0;i<K;++i) 
    {
        if(Cnt[Type[i]]==0) Kinds++;
        Cnt[Type[i]]++;
    }
    Max=Kinds + (Cnt[C]==0);
    
    for(int i=1;i<N;++i)
    {
        int Out=Type[i-1];
        Cnt[Out]--;
        if(Cnt[Out]==0) Kinds--;
        
        int In=Type[(i+K-1)%N];
        if(Cnt[In]==0) Kinds++;
        Cnt[In]++;
        
        Max=max(Max, Kinds+(Cnt[C]==0));
    }
    cout<<Max;
}