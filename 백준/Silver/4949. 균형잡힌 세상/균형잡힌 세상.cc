#include <iostream>
#include <stack>
#include <string>

using namespace std;
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    string Line;
    while(1)
    {
        getline(cin,Line);
        if(Line.empty()||Line==".") break;
        stack<char> s;
        bool IsBalanced=true;
        for(auto& C : Line)
        {
            if(C=='('||C=='[')
            {
                s.push(C);
            }
            else if(C==')')
            {
                if(s.empty()||s.top()!='(')
                {
                    IsBalanced=false;
                    break;
                }
                s.pop();
            }
            else if(C==']')
            {
                if(s.empty()||s.top()!='[')
                {
                    IsBalanced=false;
                    break;
                }
                s.pop();
            }
        }
        string Result;
        if(s.empty()&&IsBalanced) Result="yes";
        else                      Result="no";
        cout<<Result<<"\n";
    }
}