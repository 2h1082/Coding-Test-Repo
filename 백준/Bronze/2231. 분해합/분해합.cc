#include <iostream>

using namespace std;

int ComputeSum(int Num)
{
    int Result=Num;
    
    while(Num>0)
    {
        Result+=Num%10;
        Num/=10;
    }
    return Result;
}
int main()
{
    int N=0;
    cin>>N;
    
    for(int i=1;i<=N;++i)
    {
        if(N==(ComputeSum(i)))
        {
            cout<<i;
            return 0;
        }
    }
    cout<<"0";
}