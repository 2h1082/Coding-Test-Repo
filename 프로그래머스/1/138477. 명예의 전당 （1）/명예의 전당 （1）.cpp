#include <string>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> solution(int k, vector<int> score) {
    vector<int> answer;
    vector<int> fame;
    for(int i=0;i<score.size();i++){
        fame.push_back(score[i]);
        if(fame.size()>k){
            auto it=min_element(fame.begin(),fame.end());
            fame.erase(it);
        }
        
        answer.push_back(*min_element(fame.begin(),fame.end()));
    }
    return answer;
}