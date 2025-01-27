#include <string>
#include <vector>
#include <map>
using namespace std;

int solution(vector<string> want, vector<int> number, vector<string> discount) {
    int answer = 0;
    map<string, int> WantList;
    for(int i=0;i<9;++i)
    {
        ++WantList[discount[i]];
    }
    for(int j=9;j<discount.size();++j)
    {
        ++WantList[discount[j]];
        bool flag=true;
        for(int k=0;k<want.size();++k)
        {
            if(WantList[want[k]]!=number[k])
            {
                flag=false;
                break;
            }
        }
        if(flag)
        {
            ++answer;
        }
        --WantList[discount[j-9]];
    }
    return answer;
}