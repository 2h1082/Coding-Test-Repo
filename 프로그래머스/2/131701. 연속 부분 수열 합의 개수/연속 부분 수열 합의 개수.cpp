#include <string>
#include <vector>
#include <set>

using namespace std;

int solution(vector<int> elements) {
    set<int> num;
    for(int i=0;i<elements.size();++i)
    {
        int total=0;
        for(int j=i;j<i+elements.size();++j)
        {
            total+=elements[j%elements.size()];
            num.insert(total);
        }
    }
    return num.size();
}