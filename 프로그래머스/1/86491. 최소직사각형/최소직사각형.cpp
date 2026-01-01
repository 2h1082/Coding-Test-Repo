#include "bits/stdc++.h"
using namespace std;

int solution(vector<vector<int>> Sizes) 
{
    int W=0, H=0;
    for(auto& Cur : Sizes)
    {
        if(Cur[0] < Cur[1]) swap(Cur[0],Cur[1]);
        W=max(W,Cur[0]);
        H=max(H,Cur[1]);
    }
    
    return W*H;
}