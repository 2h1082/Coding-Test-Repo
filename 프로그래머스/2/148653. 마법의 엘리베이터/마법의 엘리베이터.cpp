#include <bits/stdc++.h>

using namespace std;

int solution(int storey) {
    int answer = 0;

    while(storey)
    {
        int num=storey%10;
        int NextNum=(storey/10)%10;
        if(num>5||num==5&&NextNum>=5)
        {
            storey+=(10-num);
            answer+=(10-num);
        }
        else
        {
            storey-=num;
            answer+=num;
        }
        
        storey/=10;
    }

    return answer;
}