#include <string>
#include <vector>
#include <set>
#include <unordered_map>

using namespace std;

int solution(vector<int> topping) {
    int answer = 0;
    unordered_map<int,int> Right;
    set<int> Left;
    
    for(int i : topping)
    {
        ++Right[i];
    }
    for(int i=0;i<topping.size()-1;++i)
    {
        Left.insert(topping[i]);
        --Right[topping[i]];
        if(Right[topping[i]]==0)
        {
            Right.erase(topping[i]);
        }
        if(Right.size()==Left.size())
        {
            ++answer;
        }
    }
    
    return answer;
}