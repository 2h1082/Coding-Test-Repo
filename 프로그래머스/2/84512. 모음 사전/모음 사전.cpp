#include "bits/stdc++.h"
using namespace std;

int solution(string word) 
{
    vector<int> Dist={780,155,30,5,0};
    vector<char> Alpha={'A','E','I','O','U'};
    int Cnt=0;
    for(int i=0;i<word.size();++i)
    {
        if(word[i]!='A')
        {
            for(int j=0;j<5;++j)
            {
                if(word[i]==Alpha[j])
                {
                    Cnt+=(j+1) + j*Dist[i];
                }
            }
        }
        else
        {
            ++Cnt;
        }
    }
    
    return Cnt;
}
