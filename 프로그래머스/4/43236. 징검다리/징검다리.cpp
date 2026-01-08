#include "bits/stdc++.h"
using namespace std;

int solution(int Dist, vector<int> Rocks, int N) 
{
    sort(Rocks.begin(),Rocks.end());
    int L=0, R=Dist;
    while(L<R)
    {
        int M=(L+R+1)/2;
        int Cnt=0, Prev=0;
        
        for(auto& r : Rocks)
        {
            if(r-Prev < M) Cnt++;
            else           Prev=r;
        }
        if(Dist-Prev < M)  Cnt++;
        
        if(Cnt > N) R=M-1;
        else        L=M;
    }
    
    return L;
}