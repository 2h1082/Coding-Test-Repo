#include "bits/stdc++.h"

using namespace std;

int solution(vector<int> Prior, int Location) {
    int Ans = 0;
    queue<pair<int,int>> Q;
    for(int i=0;i<Prior.size();++i) Q.push({Prior[i],i});
    
    vector<int> SortedPrior=Prior;
    sort(SortedPrior.begin(),SortedPrior.end(),greater<>());
    int SortedIdx=0;
    while(!Q.empty())
    {
        auto [P, Idx]=Q.front();
        Q.pop();
        if(P==SortedPrior[SortedIdx])
        {
            Ans++;
            SortedIdx++;
            if(Location==Idx) break;
        }
        else Q.push({P,Idx});
    }
    
    return Ans;
}