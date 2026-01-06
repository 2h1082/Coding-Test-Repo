#include "bits/stdc++.h"
using namespace std;

int Ans=0;
void DFS(const vector<int>& Num, const int& Target, int Idx, int Cur)
{
    if(Idx==Num.size())
    {
        Ans+=(Cur==Target);
        return;
    }
    DFS(Num,Target,Idx+1,Cur+Num[Idx]);
    DFS(Num,Target,Idx+1,Cur-Num[Idx]);
}
int solution(vector<int> Numbers, int Target) 
{
    DFS(Numbers,Target,0,0);
    return Ans;
}

