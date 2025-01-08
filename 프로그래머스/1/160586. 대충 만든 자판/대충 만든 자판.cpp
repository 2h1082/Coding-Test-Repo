#include <string>
#include <vector>
#include <map>

using namespace std;

vector<int> solution(vector<string> keymap, vector<string> targets) {
    vector<int> answer;
    map<char,int> minKey;
    
    for(string & s : keymap){
        for(int i=0;i<s.size();i++){
            auto it=minKey.find(s[i]);
            if(it!=minKey.end()){
                if(i+1<it->second){
                    it->second=i+1;    
                }
            }else{
                minKey[s[i]]=i+1;
            }
        }
    }
    
    for(string & str : targets){
        int count=0;
        for(int i=0;i<str.size();i++){
            auto it=minKey.find(str[i]);
            if(it!=minKey.end()){
                count+=it->second;
            }else{
                count=-1;
                break;
            }
        }
        if(count) answer.push_back(count);
    }
    return answer;
}