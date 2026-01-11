#include "bits/stdc++.h"
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    
    string S;
    cin>>S;
    
    stack<int> St;
    int Cnt=0;
    char Prev=' ';
    for(auto& c : S)
    {
        if(c=='(') St.push(c);
        else if(!St.empty())
        {
            St.pop();
            if (Prev=='(') Cnt+=St.size(); // 레이저 절단면
            else           Cnt++;          // 레이저에 잘리고 남은 마지막 조각
        }
        Prev=c;
    }
    
    cout<<Cnt;
}