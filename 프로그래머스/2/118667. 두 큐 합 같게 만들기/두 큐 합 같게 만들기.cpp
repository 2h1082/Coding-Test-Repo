#include <bits/stdc++.h>

using namespace std;

int solution(vector<int> queue1, vector<int> queue2) {
    int answer = 0;
    long long num1=0, num2=0, total=0;
    int Idx1=0, Idx2=0;
    
    num1=accumulate(queue1.begin(),queue1.end(),0);
    num2=accumulate(queue2.begin(),queue2.end(),0);
    total=(num1+num2);
    if(total%2!=0) return -1;
    total/=2;
    Idx2=queue1.size();
    copy(queue2.begin(),queue2.end(),back_inserter(queue1));
    int len=queue1.size();
    
    while(Idx1<len&&Idx2<len)
    {
        if(num1==total) return answer;
        if(num1>total)
        {
            num1-=queue1[Idx1++];
        }
        else
        {
            num1+=queue1[Idx2++];
        }
        answer++;
    }
    
    
    return -1;
}