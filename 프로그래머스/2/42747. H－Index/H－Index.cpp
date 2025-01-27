#include <string>
#include <vector>
#include <algorithm>
using namespace std;

int solution(vector<int> citations) {
    int answer = 0;
    int h=0;
    sort(citations.rbegin(),citations.rend());
    for(int i=0;i<citations.size();++i)
    {
        ++h;
        if(h>citations[i])
        {
            answer=h-1;
            break;
        }
    }
    if(h==citations.size() && citations.back()>h)
    {
        answer=h;
    }
    return answer;
}