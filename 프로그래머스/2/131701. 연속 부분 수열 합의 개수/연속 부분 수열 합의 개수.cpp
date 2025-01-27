#include <string>
#include <vector>
#include <set>

using namespace std;

int solution(vector<int> elements) {
    int answer = 0;
    set<int> num;
    for(int i=0;i<elements.size();++i)
    {
        int count=1;
        while(count<=elements.size())
        {
            int total=0;
            for(int j=0;j<count;++j)
            {
                total+=elements[(i+j)%(elements.size())];
            }
            num.insert(total);
            ++count;
        }
    }
    answer=num.size();
    return answer;
}