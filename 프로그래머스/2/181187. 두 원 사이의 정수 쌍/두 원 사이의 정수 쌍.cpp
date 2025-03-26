#include <bits/stdc++.h>

using namespace std;

long long solution(int r1, int r2) {
    long long answer = 0;
    if(r1<r2) swap(r1,r2);
    for(int x=0;x<=r1;x++)
    {
        long long MaxY=static_cast<long long>(floor(sqrt(1LL*r1*r1-1LL*x*x)));
        long long MinY;
        if(x>r2) MinY=0;
        else
        {
            MinY=static_cast<long long>(ceil(sqrt(1LL*r2*r2-1LL*x*x)));
        }
        long long count=(x==0)?(MaxY-MinY+1):(MaxY-MinY+1)*2;
        answer+=count;
    }
    answer*=2;
    answer-=(r1-r2+1)*2;
    return answer;
}