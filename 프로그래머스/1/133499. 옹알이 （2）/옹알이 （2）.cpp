#include <string>
#include <vector>
#include <regex>
using namespace std;

int solution(vector<string> babbling) {
    int answer = 0;
    vector<string> str={"aya","ye","woo","ma"};
    for(string& b : babbling){
        int i=0;
        while(i<b.size()){
            bool result=false;
            for(const auto& s : str){
                if(b.substr(i,s.size()*2)==s+s) break; //연속 발음 확인
                if(b.substr(i,s.size())==s){
                    i+=s.size();
                    result=true;
                    break;
                }
            }
            if(!result) break;
        }
        if (i==b.size()) answer++;
    }
    return answer;
}