#include <bits/stdc++.h>
using namespace std;

string solution(string Number, int K) 
{
    string Ans = "";
    stack<char> St;
    int Cnt=K; // 삭제해야할 개수
    
    for(char& c : Number)
    {
        // 숫자를 하나씩 추가하면서 스택에 저장된 이전 인덱스의 수들이 현재 추가되는 수 미만이면 삭제
        // - 스택에는 큰수부터 내림차순으로 수가 보존
        while(!St.empty() && Cnt > 0 && St.top() < c)
        {
            St.pop();
            --Cnt;
        }
        St.push(c);
    }
    // 아직 지워야할 개수가 남았다면 나머지 삭제 
    // - 내림차순으로 존재하니 위부터 삭제하면 적절
    while(!St.empty() && Cnt > 0)
    {
        St.pop();
        --Cnt;
    }
    while(!St.empty())
    {
        Ans=St.top()+Ans;
        St.pop();
    }
    
    return Ans;
}
