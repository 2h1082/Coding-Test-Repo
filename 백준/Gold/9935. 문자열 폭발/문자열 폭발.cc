#include <iostream>

using namespace std;
int main()
{
    string Input, Target, Stack;
    cin>>Input>>Target;
    
    int N=Target.length();
    for(auto& C : Input)
    {
        Stack+=C;
        int Size=Stack.length();
        if(Size>=N&&Target[N-1]==C)
        {
            bool bShouldPop=true;
            for(int i=1;i<=N;++i)
            {
                if(Target[N-i]!=Stack[Size-i])
                {
                    bShouldPop=false;
                    break;
                }
            }
            if(bShouldPop)
            {
                Stack.resize(Size-N);
            }
        }
    }
    
    if(Stack.length()==0)
    {
        cout<<"FRULA";
    }
    else
    {
        cout<<Stack;
    }
}