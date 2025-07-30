#include <iostream>

using namespace std;
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int N=0;
    cin>>N;
    
    int Count=0, CurNum=665;
    while(Count!=N)
    {
        ++CurNum;
        string Temp=to_string(CurNum);
        if(Temp.find("666")!=string::npos)
        {
            ++Count;
        }
    }
    cout<<CurNum;
}