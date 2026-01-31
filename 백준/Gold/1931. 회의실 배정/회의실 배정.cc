#include "bits/stdc++.h"
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    
    int N;
    cin>>N;
    vector<pair<int,int>> T(N);
    for(auto& [S,E]:T) cin>>S>>E;
    sort(T.begin(),T.end(),[](const auto& P1, const auto& P2){
        if(P1.second==P2.second) return P1.first < P2.first;
        return P1.second < P2.second;
    });
    int Ans=0, Cur=0;
    for(const auto& [S, E] : T)
    {
        if(Cur <= S)
        {
            Cur=E;
            ++Ans;
        }
    }
    cout<<Ans;
}