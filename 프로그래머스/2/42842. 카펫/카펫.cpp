#include <string>
#include <vector>

using namespace std;

vector<int> solution(int brown, int yellow) {
    vector<int> answer;
    int height=1;
    int width=yellow/height;
    while((width+2)*2+height*2!=brown){
        height++;
        while(yellow%height!=0){
            height++;
        }
        width=yellow/height;
    }
    answer.push_back(width+2);
    answer.push_back(height+2);
    return answer;
}