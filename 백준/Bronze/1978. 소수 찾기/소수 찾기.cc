#include <iostream>

using namespace std;

bool IsPrimeNumber(int& Num)
{
    if(Num<=1) return false;
    
    if(Num==2 || Num==3) return true;
    
    if(Num%2==0||Num%3==0) return false;
    
    for(int i=5;i*i<=Num;i+=6)
    {
        if((Num%i==0)||(Num%(i+2)==0)) return false;
    }
    return true;
}
int main()
{
    int N=0, Result=0;
    cin>>N;
    
    for(int i=0;i<N;++i)
    {
        int Num=0;
        cin>>Num;
        
        if(IsPrimeNumber(Num))
        {
            ++Result;
        }
    }
    cout<<Result;
}