#include <string>
#include <vector>
#include <cmath>

using namespace std;

long long solution(long long n) {
    double result=sqrt(n);
    if(result==floor(result)){
        return (result+1)*(result+1);
    }else{
        return -1;
    }
    
}