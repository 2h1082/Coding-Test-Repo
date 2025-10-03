#include <iostream>

using namespace std;

int GetPriority(char& A)
{
    if(A=='+'||A=='-')
    {
        return 0;
    }
    else
    {
        return 1;
    }
}
int main()
{
    string Input;
    cin>>Input;
    string Formula, Stack;
    bool bShouldPop=false;
    for(int i=0;i<Input.size();++i)
    {
        if(Input[i]>='A'&&Input[i]<='Z')
        {
            Formula+=Input[i];
        }
        else if (Input[i]=='(')
        {
            Stack+=Input[i];
        }
        else if(Input[i]==')')
        {
            while(!Stack.empty())
            {
                if(Stack.back()=='(')
                {
                    Stack.pop_back();
                    break;
                }
                Formula+=Stack.back();
                Stack.pop_back();
            }
        }
        else if(Input[i]=='*'||Input[i]=='/'||Input[i]=='+'||Input[i]=='-')
        {
            while(!Stack.empty()&&Stack.back()!='('
                 && GetPriority(Stack.back())>=GetPriority(Input[i]))
            {
                Formula+=Stack.back();
                Stack.pop_back();
            }
            Stack+=Input[i];
        }
    }
    while(!Stack.empty())
    {
        Formula+=Stack.back();
        Stack.pop_back();
    }
    cout<<Formula;
}