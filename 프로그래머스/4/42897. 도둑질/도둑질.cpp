#include "bits/stdc++.h"

using namespace std;

int RobHouse(const vector<int>& Money, int S, int E)
{
    int Prev1=0, Prev2=0;
    for(int i=S;i<=E;++i)
    {
        int Cur=max(Prev1,Prev2+Money[i]);
        Prev2=Prev1;
        Prev1=Cur;
    }
    return Prev1;
}
int solution(vector<int> Money) {
    int Ans = 0;
    int N=Money.size();
    
    int RobFirst=RobHouse(Money,0,N-2);
    int RobLast=RobHouse(Money,1,N-1);
    Ans=max(RobFirst,RobLast);
    return Ans;
}