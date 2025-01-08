#include <string>
#include <vector>

using namespace std;

string solution(vector<string> survey, vector<int> choices) {
    string answer = "";
    vector<int> score={-3,-2,-1,0,1,2,3};
    int RT=0, CF=0, JM=0, AN=0;
    for(int i=0;i<survey.size();i++){
        if(survey[i]=="RT") RT+=score[choices[i]-1];
        else if(survey[i]=="TR") RT-=score[choices[i]-1];
        else if(survey[i]=="CF") CF+=score[choices[i]-1];
        else if(survey[i]=="FC") CF-=score[choices[i]-1];
        else if(survey[i]=="JM") JM+=score[choices[i]-1];
        else if(survey[i]=="MJ") JM-=score[choices[i]-1];
        else if(survey[i]=="AN") AN+=score[choices[i]-1];
        else if(survey[i]=="NA") AN-=score[choices[i]-1];
    }
    if(RT<=0) answer+='R';
    else      answer+='T';
    if(CF<=0) answer+='C';
    else      answer+='F';
    if(JM<=0) answer+='J';
    else      answer+='M';
    if(AN<=0) answer+='A';
    else      answer+='N';
    return answer;
}