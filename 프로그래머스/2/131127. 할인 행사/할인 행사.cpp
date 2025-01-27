#include <string>
#include <vector>
#include <map>
using namespace std;

int solution(vector<string> want, vector<int> number, vector<string> discount) {
    int answer = 0;
    map<string, int> WantList;
    for(int i=0;i<want.size();++i)
    {
        WantList[want[i]]=number[i];
    }
    for(int j=0;j<discount.size()-9;++j)
    {
        map<string, int> Copy(WantList.begin(),WantList.end());
        for(int k=0;k<10;++k)
        {
            auto it=Copy.find(discount[j+k]);
            if(it!=Copy.end())
            {
                --Copy[discount[j+k]];
                if(Copy[discount[j+k]]==0)
                {
                    Copy.erase(discount[j+k]);   
                }
            }
        }
        if(Copy.empty())
        {
            answer++;
        }
    }
    return answer;
}