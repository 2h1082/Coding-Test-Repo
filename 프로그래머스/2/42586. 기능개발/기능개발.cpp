#include <string>
#include <vector>

using namespace std;

vector<int> solution(vector<int> progresses, vector<int> speeds) {
    vector<int> answer;
    vector<int> period(speeds.size());
    for(int i=0;i<speeds.size();++i)
    {
        period[i]=(100-progresses[i]+speeds[i]-1)/speeds[i];
    }
    int count=1;
    int prevPeriod=period[0];
    for(int j=1;j<speeds.size();++j)
    {
        if(prevPeriod<period[j])
        {
            answer.push_back(count);
            prevPeriod=period[j];
            count=0;
        }
        ++count;
    }
    answer.push_back(count);
    return answer;
}