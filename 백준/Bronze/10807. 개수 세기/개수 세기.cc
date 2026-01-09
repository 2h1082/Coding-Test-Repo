#include "bits/stdc++.h"
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    
    map<int,int> Cnt;
    int N, V;
    cin>>N;
    for(int i=0;i<N;++i)
    {
        int Num;
        cin>>Num;
        Cnt[Num]++;
    }
    cin>>V;
    
    cout<<Cnt[V];
}