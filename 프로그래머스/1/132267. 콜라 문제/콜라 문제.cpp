#include <string>
#include <vector>
#include <iostream>
using namespace std;

int solution(int a, int b, int n) {
    int answer = 0;
    int full=n;
    while(full>=a){
        cout<<full<<" ";
        int exchange=(full/a)*b;
        answer+=exchange;
        full=full%a+exchange;
    }
    return answer;
}