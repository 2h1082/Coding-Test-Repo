#include "bits/stdc++.h"

using namespace std;

bool solution(vector<string> phone_book) {
    bool answer = true;
    
    map<string,int> Num;
    for(auto& s : phone_book) Num[s]++;
    
    for(auto& s : phone_book)
    {
        string Cur;
        for(int i=0;i<s.length()-1;++i)
        {
            Cur+=s[i];
            if(Num[Cur]>0)
            {
                answer=false;
                break;
            }
        }
    }
    
    return answer;
}