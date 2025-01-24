#include <string>
#include <vector>

using namespace std;

long long solution(int n) {
    long long answer = 0;
    vector<long long> base={1,2};
    for(int i=2;i<n;i++){
        int temp=base[i-1]%1234567+base[i-2]%1234567;
        base.push_back(temp);
    }
    answer=base[n-1]%1234567;
    return answer;
}