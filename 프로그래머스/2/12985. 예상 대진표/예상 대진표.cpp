#include <iostream>

using namespace std;

int solution(int n, int a, int b)
{
    int answer = 0;

    while(1){
        a = (a%2!=0 ? a/2+1 : a/2);
        b = (b%2!=0 ? b/2+1 : b/2);
        answer++;
        if(a==b) break;
    }

    return answer;
}