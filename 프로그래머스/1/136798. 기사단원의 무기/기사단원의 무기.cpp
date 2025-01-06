#include <string>
#include <vector>

using namespace std;

int countDivisor(int n){
    int count=0;
    if(n<=0) return 0;
    
    for(int i=1;i*i<=n;i++){
        if(n%i==0) {
            count++;
            if(i!=n/i) count++;
        }
    }
    return count;
}

int solution(int number, int limit, int power) {
    int answer = 0;
    for(int i=1;i<=number;i++){
        int count=countDivisor(i);
        if(count<=limit){
            answer+=count;
        }else{
            answer+=power;
        }
    }
    return answer;
}