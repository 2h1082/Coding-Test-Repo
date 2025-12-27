#include "bits/stdc++.h"

using namespace std;

int solution(int Dist, vector<int> Rocks, int N) 
{
    int Ans=0;
    sort(Rocks.begin(),Rocks.end());
    
    int L=1, R=Dist;
    while(L<=R)
    {
        int M=(L+R)/2;
        int Cnt=0, Prev=0;
        for(int i=0;i<Rocks.size();++i)
        {
            if(Rocks[i] - Prev < M) ++Cnt;
            else                    Prev=Rocks[i];
        }
        if(Dist - Prev < M) ++Cnt;
        
        if(Cnt <= N)
        {
            Ans=M;
            L=M+1;
        }
        else
        {
            R=M-1;
        }
    }
    return Ans;
}