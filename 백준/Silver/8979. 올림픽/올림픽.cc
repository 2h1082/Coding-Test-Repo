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
    
    int N,K;
    cin>>N>>K;
    vector<Medal> Nation(N);
    for(auto& n : Nation)
    {
        cin>>n.Num>>n.Gold>>n.Silver>>n.Bronze;
    }
    sort(Nation.begin(),Nation.end(),greater<>());
    int Rank=0;
    for(int i=1;i<N;++i)
    {
        if(Nation[i-1]==Nation[i]) continue;
        Rank++;
        if(Nation[i].Num==K) break;
    }
    cout<<Rank;
}