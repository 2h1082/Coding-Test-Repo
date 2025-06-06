#include <string>
#include <vector>

using namespace std;

string solution(vector<string> cards1, vector<string> cards2, vector<string> goal) {
    string answer = "No";
    int idx1=0, idx2=0;
    for(int i=0;i<goal.size();i++){
        if(goal[i]==cards1[idx1]){
            idx1++;
        }else if(goal[i]==cards2[idx2]){
            idx2++;
        }
    }
    if(goal.size()==idx1+idx2){
        answer="Yes";
    }
    return answer;
}