#include <string>
#include <vector>
#include <map>
#include <algorithm>
using namespace std;

int solution(int k, vector<int> tangerine) 
{
    int answer = 0;
    map<int,int> kind;
    for(const int i : tangerine)
    {
        kind[i]++;
    }
    vector<pair<int,int>> frequency(kind.begin(),kind.end());
    sort(frequency.begin(),frequency.end(),[](const pair<int,int>& a, const pair<int,int>& b){return a.second>b.second;});
    int total=0;
    for(const auto& p : frequency)
    {
        total+=p.second;
        answer++;
        if(k<=total)
        {
            break;
        }
    }
    return answer;
}