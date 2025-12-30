#include "bits/stdc++.h"
using namespace std;

int solution(int BridgeLength, int Weight, vector<int> TruckWeights) 
{
    int N=TruckWeights.size(), Time=0, CurWeight=0;
    queue<pair<int,int>> Q;
    for(int i=0;i<N;++i)
    {
        Time++;
        
        while(!Q.empty() && Time >= Q.front().second+BridgeLength)
        {
            CurWeight-=Q.front().first;
            Q.pop();
        }
        
        while(!Q.empty() && CurWeight+TruckWeights[i] > Weight)
        {
            CurWeight-=Q.front().first;
            Time=Q.front().second+BridgeLength;
            Q.pop();
        }
        Q.push({TruckWeights[i],Time});
        CurWeight+=TruckWeights[i];
    }
    
    return Q.back().second+BridgeLength;
}