#include <string>
#include <vector>
#include <map>
#include <set>
#include <sstream>

using namespace std;

vector<int> solution(vector<string> id_list, vector<string> report, int k) {
    vector<int> answer(id_list.size(), 0);
    map<string, int> idIndex;
    map<string,set<string>> reportList;
    
    for(int i=0;i<id_list.size();i++){
        idIndex[id_list[i]]=i;
    }
    
    for(string s : report){
        stringstream ss(s);
        string from, to;
        ss>>from>>to;
        reportList[to].insert(from);
    }
    for(auto iter : reportList){
        if(iter.second.size()>=k){
            for(auto iter2 : iter.second){
                answer[idIndex[iter2]]++;
            }
        }
    }
    return answer;
}