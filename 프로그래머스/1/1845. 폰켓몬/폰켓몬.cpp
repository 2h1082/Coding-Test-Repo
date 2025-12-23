#include "bits/stdc++.h"
using namespace std;

int solution(vector<int> nums)
{
    int answer = 0;
    int TypeCnt=0;
    map<int,int> Cnt;
    for(auto& n : nums)
    {
        Cnt[n]++;
        if(Cnt[n]==1) TypeCnt++;
    }
    int Half=nums.size()/2;
    answer=min(TypeCnt,Half);
    return answer;
}