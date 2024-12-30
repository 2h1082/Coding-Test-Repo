#include <string>
#include <vector>

using namespace std;

string solution(string s) {
    string answer = "";
    int len=s.size()/2;
    if(s.size()%2==0){
        answer=s.substr(len-1,2);
    }else{
        answer=s[len];
    }
    return answer;
}