#include "bits/stdc++.h"
using namespace std;

int solution(int N, vector<int> Lost, vector<int> Reserve) 
{
    int Ans=N-Lost.size();
    sort(Lost.begin(),Lost.end());
    sort(Reserve.begin(),Reserve.end());
    for(int& l : Lost)
    {
        for(int& r : Reserve)
        {
            if(l==r)
            {
                l=-1;
                r=-1;
                ++Ans;
                break;
            }
        }
    }
    for(int i=0;i<Lost.size();++i)
    {
        for(int j=0;j<Reserve.size();++j)
        {
            if(Lost[i]-1==Reserve[j] || Lost[i]+1==Reserve[j])
            {
                Reserve[j]=-1;
                Lost[i]=-1;
                ++Ans;
                break;
            }
        }
    }
    
    return Ans;
}