#include <stack>
#include <iostream>

using namespace std;
int main()
{
    int T=0;
    cin>>T;
    
    for(int i=0;i<T;++i)
    {
        string Text;
        cin>>Text;
        
        stack<char> s;
        bool Valid=true;
        for(auto& C : Text)
        {
            if(C=='(')
            {
                s.push(C);
            }
            else if(C==')')
            {
                if(s.empty()||s.top()!='(')
                {
                    Valid=false;
                    break;
                }
                s.pop();
            }
        }
        string Result="NO";
        if(s.empty()&&Valid) Result="YES";
        cout<<Result<<"\n";
    }
}