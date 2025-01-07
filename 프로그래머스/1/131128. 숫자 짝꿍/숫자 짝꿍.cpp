#include <string>
#include <vector>
#include <algorithm>

using namespace std;

string solution(string X, string Y) {
    string answer = ""; /*
    for(char &cX : X){
        size_t pos=Y.find(cX);
        if(pos!=string::npos){
            if(cX=='0'&& answer=="0") continue;
            answer+=cX;
            Y.erase(pos,1);
        }
    }
    if(answer.empty()){
        answer="-1";
    }else{
        sort(answer.rbegin(),answer.rend());   
    }
    */
    vector<int> cnt1(10,0);
    vector<int> cnt2(10,0);
    for(int i=0;i<X.size();i++){
        cnt1[X[i]-48]++;
    }
    for(int i=0;i<Y.size();i++){
        cnt2[Y[i]-48]++;
    }
    for(int i=0;i<10;i++){
        if(cnt1[i]>cnt2[i]){
            for(int j=0;j<cnt2[i];j++){
                answer+=i+48;
            }
        }else{
            for(int j=0;j<cnt1[i];j++){
                answer+=i+48;
            }
        }
    }
    if(answer.empty()) return "-1";
    sort(answer.rbegin(),answer.rend());
    if(answer[0]=='0') return "0";
    return answer;
}