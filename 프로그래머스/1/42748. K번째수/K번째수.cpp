#include <string>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> solution(vector<int> array, vector<vector<int>> commands) {
    vector<int> answer;
    for(vector<int> v : commands){
        vector<int> temp(array.begin()+v.at(0)-1,array.begin()+v.at(1));
        sort(temp.begin(),temp.end());
        answer.push_back(temp[v.at(2)-1]);
    }
    return answer;
}