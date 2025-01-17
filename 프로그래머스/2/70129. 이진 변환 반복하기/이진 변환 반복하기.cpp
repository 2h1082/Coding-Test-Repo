#include <string>
#include <vector>
#include <bitset>

using namespace std;

vector<int> solution(string s) {
    vector<int> answer;
    int count=0;
    int zeroCnt=0;
    while(s!="1") {
        int oneCnt=0;
        for(char &c : s){
            if(c=='1'){
                oneCnt++;
            }
            else{
                zeroCnt++;
            }
        }
        s.clear();
        while(oneCnt>0){
            s=char((oneCnt%2)+'0')+s;
            oneCnt/=2;
        }
        count++;
    }
    answer.push_back(count);
    answer.push_back(zeroCnt);
    return answer;
}