#include <string>
#include <vector>

using namespace std;

int answer=0;

void Sum(int index,vector<int> numbers, int target, int total)
{
    if(index==numbers.size())
    {
        if(total==target)
        {
            ++answer;
        }
        return;
    }
    Sum(index+1,numbers,target,total+numbers[index]);
    Sum(index+1,numbers,target,total-numbers[index]);
}

int solution(vector<int> numbers, int target) {
    Sum(0,numbers,target,0);
    return answer;
}

