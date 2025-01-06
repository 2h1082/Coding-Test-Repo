#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int solution(int k, int m, vector<int> score) {
    int answer = 0;
    sort(score.rbegin(),score.rend());
    for(int i=0;i+m<=score.size();i+=m){
        answer+=score[i+m-1]*m;
    }
    return answer;
}