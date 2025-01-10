#include <string>
#include <vector>
#include <map>
#include <iostream>
using namespace std;

vector<string> solution(vector<string> players, vector<string> callings) {
    vector<string> answer=players;
    map<string, int> PlayerIndex;
    for(int i=0;i<players.size();i++){
        PlayerIndex[players[i]]=i;
    }
    for(int i=0;i<callings.size();i++){
        int idx=PlayerIndex[callings[i]];
        string temp=answer[idx];
        answer[idx]=answer[idx-1];
        answer[idx-1]=temp;
        PlayerIndex[temp]=idx-1;
        PlayerIndex[answer[idx]]=idx;
    }
    return answer;
}