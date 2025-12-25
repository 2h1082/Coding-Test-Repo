#include "bits/stdc++.h"

using namespace std;

int solution(vector<int> P, int Limit) {
    int Ans = 0;
    sort(P.begin(),P.end());
    
    int L=0, R=P.size()-1;
    while(L<=R)
    {
        if(P[L]+P[R] <= Limit) L++;
        R--;
        Ans++;
    }
    return Ans;
}