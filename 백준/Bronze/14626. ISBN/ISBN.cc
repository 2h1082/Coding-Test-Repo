#include <iomanip>
#include <iostream>
#include <vector>

using namespace std;
int main()
{
    string ISBN;
    cin >> ISBN;

    int M=1, Sum=0;
    int Divisor=1;
    for (int i=0;i<ISBN.size();++i)
    {
        M = i%2==0 ? 1 : 3;
        if (ISBN[i]!='*') Sum+=(ISBN[i]-'0')*M;
        else Divisor=M;
    }
    int Result=0;
    for(int i=0;i<10;++i)
    {
        if((Sum+(i*Divisor))%10==0) Result=i;
    }
    
    cout<<Result;
}