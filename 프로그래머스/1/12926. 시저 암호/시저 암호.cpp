#include <string>
#include <vector>

using namespace std;

string solution(string s, int n) {
    string answer = "";
    for(char c : s){
        if(c>=65&&c<=90){ //A~Z
            answer+=(c-'A'+n)%26+'A';
        }
        else if(c>=97&&c<=122){
            answer+=(c-'a'+n)%26+'a';
        }
        else{
            answer+=c;
        }
    }
    return answer;
}