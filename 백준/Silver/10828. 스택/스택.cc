#include <stack>
#include <iostream>

using namespace std;
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int N=0;
    cin>>N;
    stack<int> s;
    for(int i=0;i<N;++i)
    {
        string Command;
        cin>>Command;
        if(Command=="push")
        {
            int Num=0;
            cin>>Num;
            s.push(Num);
        }
        else if(Command=="top")
        {
            int Result=-1;
            if(!s.empty()) Result=s.top();
            cout<<Result<<"\n";
        }
        else if(Command=="size")
        {
            cout<<s.size()<<"\n";
        }
        else if(Command=="empty")
        {
            int Result=s.empty()?1:0;
            cout<<Result<<"\n";
        }
        else if(Command=="pop")
        {
            int Result=-1;
            if(!s.empty())
            {
                Result=s.top();
                s.pop();   
            }
            cout<<Result<<"\n";
        }
    }
}