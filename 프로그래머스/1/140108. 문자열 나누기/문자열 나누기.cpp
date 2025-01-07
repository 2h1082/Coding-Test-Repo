#include <string>
#include <vector>
#include <iostream>
using namespace std;

int solution(string s) {
    int answer = 0;
    int i=0;
    while(i<s.size()){
        char c=s[i];
        int cnt1=1, cnt2=0;
        if(i+1==s.size()){
            answer++;
            i+=1;
        }
        for(int j=i+1;j<s.size();j++){
            if(c!=s[j]) cnt2++;
            else cnt1++;
            
            if(cnt1==cnt2){
                answer++;
                i=j+1;
                break;
            }else if(j+1==s.size()){
                answer++;
                i=j+1;
                break;
            }
        }
    }
    return answer;
}