#include <bits/stdc++.h>

using namespace std;

long long solution(int k, int d) {
    long long answer = 0;
    for(int x=0;x<=d;x+=k)
    {
        int y=sqrt(1LL*d*d-1LL*x*x);
        answer+=(y/k)+1;
    }
    return answer;
}