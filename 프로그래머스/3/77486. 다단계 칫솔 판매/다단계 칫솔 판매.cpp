#include <bits/stdc++.h>

using namespace std;

vector<int> solution(vector<string> enroll, vector<string> referral, vector<string> seller, vector<int> amount) {
    vector<int> answer(enroll.size(),0);
    unordered_map<string,string> parent;
    unordered_map<string,int> idx;
    parent["-"]="end";
    for(int i=0;i<enroll.size();i++)
    {
        parent[enroll[i]]=referral[i];
        idx[enroll[i]]=i;
    }
    
    for(int i=0;i<seller.size();i++)
    {
        string s=seller[i];
        int a=amount[i]*100;
        while(parent[s]!="end"&&a>0)
        {
            int ref=a/10;
            answer[idx[s]]+=a-ref;
            s=parent[s];
            a=ref;
        }
    }
    return answer;
}