#include <string>
#include <vector>

using namespace std;

int solution(int n) {
    int answer = 1;
    int prev=0;
    
    for(int i=2;i<=n;i++){
        int temp=(prev+answer)%1234567;
        prev=answer;
        answer=temp;
    }
    
    return answer;
}