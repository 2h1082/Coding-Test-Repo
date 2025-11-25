#include "bits/stdc++.h"
using namespace std;

struct Medal
{
    int Num,Gold,Silver,Bronze;
    
    bool operator >(const Medal& other) const
    {
        if(Gold!=other.Gold) return Gold>other.Gold;
        if(Silver!=other.Silver) return Silver>other.Silver;
        return Bronze>other.Bronze;
    }
    bool operator ==(const Medal& other) const
    {
        return (Gold==other.Gold && Silver==other.Silver && Bronze==other.Bronze);
    }
};
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    int N,K,Idx;
    cin>>N>>K;
    vector<Medal> Nation(N);
    for(int i=0;i<N;++i)
    {
        cin>>Nation[i].Num>>Nation[i].Gold>>Nation[i].Silver>>Nation[i].Bronze;
        if(Nation[i].Num==K) Idx=i;
    }
    
    int Rank=1;
    for(int i=0;i<N;++i)
    {
        if(i==Idx) continue;
        if(Nation[i]>Nation[Idx]) Rank++;
    }
    cout<<Rank;
}