#include <iostream>
#include <stdexcept>
#include <vector>

using namespace std;
string IsFizzBuzz(int Num)
{
    string Result;
    if(Num%3==0) Result+="Fizz";
    if(Num%5==0) Result+="Buzz";
    if(Result.empty()) Result=to_string(Num);
    return Result;
}
bool IsNumber(string T)
{
    try
    {
        size_t Pos;
        int Num=stoi(T,&Pos);
        return Pos==T.length();
    }
    catch(const invalid_argument& e)
    {
        return false;
    }
    catch(const out_of_range& e)
    {
        return false;
    }
}
int main()
{
    vector<string> Inputs(3);
    int NextNum=0;
    for(int i=0;i<3;++i)
    {
        cin>>Inputs[i];
        if(IsNumber(Inputs[i]))
        {
            NextNum=stoi(Inputs[i])+3-i;
        }
    }
    string Result=IsFizzBuzz(NextNum);
    cout<<Result;
}