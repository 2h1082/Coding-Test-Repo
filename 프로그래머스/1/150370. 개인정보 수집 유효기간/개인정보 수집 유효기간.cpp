#include <string>
#include <vector>
#include <map>
#include <iostream>
using namespace std;

vector<string> split(string str, char delimiter){
    vector<string> token;
    size_t start=0;
    size_t end=str.find(delimiter);
    while(end!=string::npos){
        token.push_back(str.substr(start,end-start));
        start=end+1;
        end=str.find(delimiter,start);
    }
    token.push_back(str.substr(start));
    return token;
}

void computeDate(vector<int>& date, int limit){
    int plusMonth=(date[2]+26)/28;
    date[2]=date[2]+27<=28 ? date[2]+27 : (date[2]+27)%28;
    int plusYear=(date[1]+limit+plusMonth-2)/12;
    date[1]=(date[1]+plusMonth+limit-2)%12+1;
    date[0]=date[0]+plusYear;
}

vector<int> solution(string today, vector<string> terms, vector<string> privacies) {
    vector<int> answer;
    vector<string> temp=split(today,'.');
    vector<int> date;
    map<string,int> rule;
    for(const auto& t : temp){
        date.push_back(stoi(t));
    }
    for(int i=0;i<terms.size();i++){
        vector<string> period=split(terms[i],' ');
        rule[period[0]]=stoi(period[1]);
    }
    for(int i=0;i<privacies.size();i++){
        vector<string> infor=split(privacies[i],' ');
        vector<string> temp2=split(infor[0],'.');
        vector<int> date2;
        for(const auto& t2 : temp2){
            date2.push_back(stoi(t2));
        }
        int limit=rule[infor[1]];
        //cout<<date2[0]<<"."<<date2[1]<<"."<<date2[2]<<endl;
        computeDate(date2,limit);
        //cout<<date2[0]<<"."<<date2[1]<<"."<<date2[2]<<endl;
        if(date2[0]<date[0]) answer.push_back(i+1);
        else if(date2[0]==date[0]){
            if(date2[1]<date[1]) answer.push_back(i+1);
            else if(date2[1]==date[1]){
                if(date2[2]<date[2]) answer.push_back(i+1);
            }
        }
    }
    return answer;
}