#include <string>
#include <vector>
#include <iostream>
using namespace std;

int solution(string s) {
    int answer = 0;
    int cnt1=1, cnt2=0;
    char c=s[0];
    for(int i=1;i<s.size();i++){
        if(c==s[i]) cnt1++;
        else        cnt2++;
        
        if(cnt1==cnt2){
            cnt1=0;
            cnt2=0;
            answer++;
            c=s[i+1];
        }
    }
    if(cnt1>0) answer++;
    
    return answer;
}