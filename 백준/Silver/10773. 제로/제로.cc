#include <iostream>
#include <stack>

using namespace std;
int main()
{
    int K=0;
    cin>>K;
    stack<int> s;
    for(int i=0;i<K;++i)
    {
        int Num=0;
        cin>>Num;
        if(Num==0&&!s.empty())
        {
            s.pop();
        }
        else
        {
            s.push(Num);
        }
    }
    int Result=0;
    while(!s.empty())
    {
        Result+=s.top();
        s.pop();
    }
    cout<<Result;
}