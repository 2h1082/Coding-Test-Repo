#include <string>
#include <vector>
#include <cmath>
#include <iostream>

using namespace std;

vector<long long> solution(vector<long long> numbers) {
    vector<long long> answer;
    
    for(long long l : numbers)
    {
        if((l&1)==0) //짝수
        {
            answer.push_back(l+1);
        }
        else
        {
            long long bit=1;
            while(l&bit) //처음으로 만나는 0에서 멈춤
            {
                bit<<=1;
            }
            answer.push_back(l+bit-(bit>>1));
        }
    }
    return answer;
}