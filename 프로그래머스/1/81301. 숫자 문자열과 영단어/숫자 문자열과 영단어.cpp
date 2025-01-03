#include <string>
#include <vector>

using namespace std;

int solution(string s) {
    int answer = 0;
    int cnt=0;
    while(cnt!=s.size()){
        answer*=10;
        if(s[cnt]=='o'){
            if(s.substr(cnt,3)=="one"){
                answer+=1;
                cnt+=3;
            }
        }else if(s[cnt]=='t'){
            if(s.substr(cnt,3)=="two"){
                answer+=2;
                cnt+=3;
            }else if(s.substr(cnt,5)=="three"){
                answer+=3;
                cnt+=5;
            }
        }else if(s[cnt]=='f'){
            if(s.substr(cnt,4)=="four"){
                answer+=4;
                cnt+=4;
            }else if(s.substr(cnt,4)=="five"){
                answer+=5;
                cnt+=4;
            }
        }
        else if(s[cnt]=='s'){
            if(s.substr(cnt,3)=="six"){
                answer+=6;
                cnt+=3;
            }else if(s.substr(cnt,5)=="seven"){
                answer+=7;
                cnt+=5;
            }
        }else if(s[cnt]=='e'){
            if(s.substr(cnt,5)=="eight"){
                answer+=8;
                cnt+=5;
            }
        }else if(s[cnt]=='n'){
            if(s.substr(cnt,4)=="nine"){
                answer+=9;
                cnt+=4;
            }
        }else if(s[cnt]=='z'){
            if(s.substr(cnt,4)=="zero"){
                cnt+=4;
            }
        }else{
            answer+=s[cnt]-'0';
            cnt++;
        }
    }
    return answer;
}