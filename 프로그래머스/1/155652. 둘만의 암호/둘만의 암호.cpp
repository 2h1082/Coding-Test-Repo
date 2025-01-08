#include <string>
#include <vector>
#include <iostream>
using namespace std;

string solution(string s, string skip, int index) {
    string answer = "";
    vector<bool> skipAlphabet(26,false);
    
    for(int i=0;i<skip.size();i++){
        skipAlphabet[skip[i]-'a']=true;
    }
    for(int i=0;i<s.size();i++){
        int skipCnt=0;
        for(int j=0;j<=index+skipCnt;j++){
            if(skipAlphabet[(s[i]-'a'+j)%26]==true){
                skipCnt++;
            }
        }
        answer+= (s[i]+skipCnt+index) > 'z' ? 'a'+(s[i]+skipCnt+index-'a')%26 : (s[i]+skipCnt+index);
    }
    return answer;
}