#include <string>
#include <vector>
#include <cctype>

using namespace std;

string solution(string s) {
    string answer = "";
    int cnt=0;
    for (char str : s){
        if(str==' '){
            answer+=str;
            cnt=0;
        }
        else{
            answer+= (cnt==0 ? toupper(str) : (cnt%2)==0 ? toupper(str) : tolower(str));
            cnt++;
        }
    }
    return answer;
}