#include <string>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> solution(vector<int> answers) {
    vector<int> answer;
    vector<int> num1={1,2,3,4,5};
    vector<int> num2={2,1,2,3,2,4,2,5};
    vector<int> num3={3,3,1,1,2,2,4,4,5,5};
    int sol1=0, sol2=0, sol3=0;
    for(int i=0;i<answers.size();i++){
        if(num1[i%5]==answers[i]) sol1++;
        if(num2[i%8]==answers[i]) sol2++;
        if(num3[i%10]==answers[i]) sol3++;
    }
    int Max=max({sol1,sol2,sol3});
    if (sol1==Max) answer.push_back(1);
    if (sol2==Max) answer.push_back(2);
    if (sol3==Max) answer.push_back(3);
    return answer;
}