#include "bits/stdc++.h"
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    
    int N, C;
    cin>>N>>C;
    unordered_map<int, int> Cnt, Idx;
    vector<int> A(N);
    for(int i=0;i<N;++i)
    {
        cin>>A[i];
        if(!Cnt[A[i]]) Idx[A[i]]=i;
        ++Cnt[A[i]];
    }
    sort(A.begin(),A.end(),[&](const auto& a, const auto& b){
        if(Cnt[a] != Cnt[b]) return Cnt[a] > Cnt[b];
        return Idx[a] < Idx[b];
    });
    for(auto& a : A) cout<<a<<' ';
}