#include <string>
#include <vector>
#include <map>
using namespace std;

int solution(vector<vector<string>> clothes) {
    int answer = 1;
    map<string,int> ClothCount;
    for(int i=0;i<clothes.size();++i)
    {
        ++ClothCount[clothes[i][1]];
    }
    for(auto it=ClothCount.begin();it!=ClothCount.end();++it)
    {
        answer*=(it->second+1);
    }
    return answer-1;
}