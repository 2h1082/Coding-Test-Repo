#include "bits/stdc++.h"
using namespace std;

vector<int> solution(int Brown, int Yellow) 
{
    vector<int> Ans(2,0);
    int Total=Brown+Yellow;
    int W=0;
    for(int H=3;H<=sqrt(Total);++H)
    {
        if(!(Total%H)) 
        {
            W=Total/H;
            if((W-2)*(H-2)==Yellow)
            {
                Ans[0]=W;
                Ans[1]=H;
                break;
            }
        }
    }
    
    return Ans;
}