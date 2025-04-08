#include <bits/stdc++.h>

using namespace std;

vector<int> solution(vector<string> operations) {
    vector<int> answer(2,0);
    multiset<int> DQ;
    for(auto& op:operations)
    {
        if(op[0]=='I')
        {
            int num=stoi(op.substr(2));
            DQ.insert(num);
        }
        else if(op[0]=='D')
        {
            if(DQ.empty()) continue;
            if(op[2]=='1') DQ.erase(*prev(DQ.end()));
            else if(op[2]=='-') DQ.erase(DQ.begin());
        }
    }
    if(!DQ.empty())
    {
        answer[0]=*prev(DQ.end());
        answer[1]=*DQ.begin();
    }
    
    return answer;
}