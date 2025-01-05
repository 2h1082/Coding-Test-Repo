#include <string>
#include <vector>

using namespace std;

vector<int> solution(string s) {
    vector<int> answer;
    answer.push_back(-1);
    for(int i=1;i<s.size();i++){
        int result=-1;
        for(int j=0;j<i;j++){
            if(s[i]==s[j]){
                result=i-j;
            }
        }
        answer.push_back(result);
    }
    return answer;
}