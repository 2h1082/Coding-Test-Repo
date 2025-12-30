#include <bits/stdc++.h>

using namespace std;

vector<int> solution(vector<string> Op) 
{
    vector<int> Ans(2,0);
    multiset<int> S;
    
    for(auto& O : Op)
    {
        char op=O[0];
        int Num=stoi(O.substr(2));
        if(op=='I')
        {
            S.insert(Num);
        }
        else if(op=='D' && !S.empty())
        {
            if(Num==1)
            {
                S.erase(prev(S.end()));
            }
            else if(Num==-1)
            {
                S.erase(S.begin());
            }
        }
    }
    if(!S.empty())
    {
        Ans[0]=*prev(S.end());
        Ans[1]=*S.begin();
    }
    
    
    return Ans;
}