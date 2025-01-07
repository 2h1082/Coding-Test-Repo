#include <string>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> solution(vector<int> lottos, vector<int> win_nums) {
    vector<int> answer;
    int zeroCnt=0;
    int correctNum=0;
    
    for(int i=0;i<lottos.size();i++){
        if(lottos[i]==0) zeroCnt++;
        else{
            auto it=find(win_nums.begin(),win_nums.end(),lottos[i]);
            if(it!=win_nums.end()) correctNum++;
        }
    }
    switch (zeroCnt+correctNum){
        case 6:
            answer.push_back(1);
            break;
        case 5:
            answer.push_back(2);
            break;
        case 4:
            answer.push_back(3);
            break;
        case 3:
            answer.push_back(4);
            break;
        case 2:
            answer.push_back(5);
            break;
        default:
            answer.push_back(6);
            break;
    }
    switch (correctNum){
        case 6:
            answer.push_back(1);
            break;
        case 5:
            answer.push_back(2);
            break;
        case 4:
            answer.push_back(3);
            break;
        case 3:
            answer.push_back(4);
            break;
        case 2:
            answer.push_back(5);
            break;
        default:
            answer.push_back(6);
            break;
    }
    return answer;
}