#include <string>
#include <vector>

using namespace std;

int solution(string t, string p) {
    int answer = 0;
    string temp;
    for(int i=0;i<t.size()-p.size()+1;i++){
        temp=t.substr(i,p.size());
        if(stoll(temp)<=stoll(p)){
            answer++;
        }
    }
    return answer;
}