#include <bits/stdc++.h>
using namespace std;

string solution(vector<string> participant, vector<string> completion) {
    string answer = "";
    
    unordered_map<string,int> Cnt;
    for(auto& s : completion)  Cnt[s]++;
    for(auto& s : participant)
    {
        Cnt[s]--;
        if(Cnt[s]<0)
        {
            answer=s;
        }
    }
    return answer;
}