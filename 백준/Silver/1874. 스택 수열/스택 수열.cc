#include <iostream>
#include <stack>
#include <vector>

using namespace std;
int main()
{
    int N=0;
    cin>>N;
    vector<int> T(N);
    vector<string> Result;
    for(int i=0;i<N;++i)
    {
        cin>>T[i];
    }
    stack<int> s;
    int Idx=0;
    int Cur=1;
    while(Idx<N)
    {
        if(!s.empty())
        {
            if(s.top()==T[Idx])
            {
                s.pop();
                Result.push_back("-");
                Idx++;
            }
            else if(s.top()<T[Idx])
            {
                s.push(Cur++);
                Result.push_back("+");
            }
            else
            {
                break;
            }
        }
        else
        {
            s.push(Cur++);
            Result.push_back("+");
        }
    }
    if(!s.empty())
    {
        Result.clear();
        Result.push_back("NO");
    }
    for(auto& C:Result)
    {
        cout<<C<<"\n";
    }
}