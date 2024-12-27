#include <string>
#include <vector>

using namespace std;

int solution(int num) {
    int answer = 0;
    long num2=num;
    if(num==1)
        return 0;
    
    while(num2!=1){  
        if(num2%2){
            num2*=3;
            num2+=1;
        }else{
            num2/=2;
        }
        answer+=1;
        if(answer==500)
            return -1;
    }
    return answer;
}