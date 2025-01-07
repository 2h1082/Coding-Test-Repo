#include <string>
#include <vector>
#include <algorithm>
#include <iostream>
using namespace std;

int solution(int n, vector<int> lost, vector<int> reserve) {
    int answer = n-lost.size();
    sort(lost.begin(),lost.end());
    sort(reserve.begin(),reserve.end());
    for(int i=0;i<lost.size();i++){
        for(int j=0;j<reserve.size();j++){
            if(lost[i]==reserve[j]) {
                reserve[j]=-2;
                lost[i]=-2;
                answer++;
                break;
            }
        }
    }
    for(int i=0;i<lost.size();i++){
        for(int j=0;j<reserve.size();j++){
            if((lost[i]-1==reserve[j]) || (lost[i]==reserve[j]-1)){
                lost[i]=-2;
                reserve[j]=-2;
                answer++;
                break;
            }
        }
    }
    return answer;
}