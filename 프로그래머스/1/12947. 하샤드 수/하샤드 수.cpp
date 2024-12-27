#include <string>
#include <vector>

using namespace std;

bool solution(int x) {
    bool answer = true;
    int num=x;
    int sum=0;
    while(num>=1){
        sum+=num%10;
        num/=10;
    }
    if(x%sum){
        answer=false;
    }
    return answer;
}