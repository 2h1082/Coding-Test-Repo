#include <string>
#include <vector>
#include <algorithm>
using namespace std;

int solution(vector<int> ingredient) {
    int answer = 0;
    vector<int> bugger={1,2,3,1};
    vector<int> stack;
    
    for(int i=0;i<ingredient.size();i++){
        stack.push_back(ingredient[i]);
        if(stack.size()>=4 && 
           stack[stack.size()-4]==bugger[0] && 
           stack[stack.size()-3]==bugger[1] &&
           stack[stack.size()-2]==bugger[2] &&
           stack[stack.size()-1]==bugger[3] ){
            stack.erase(stack.end()-4,stack.end());
            answer++;
        }
    }
    
    
    return answer;
}