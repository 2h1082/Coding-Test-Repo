#include <iostream>
#include <vector>

using namespace std;
long long D=1000000007;
long long Power(long long& Origin, long long Multiplier)
{
    if(Multiplier==1)
    {
        return Origin%D;
    }
    long long Num=Power(Origin,Multiplier/2);
    Num=Num*Num%D;
    if(Multiplier%2)
    {
        return Num*Origin%D;
    }
    else
    {
        return Num;
    }
}
int main()
{
    int M=0;
    cin>>M;
    long long Total=0;
    for(int i=0;i<M;++i)
    {
        long long Num=0, Sum=0;
        cin>>Num>>Sum;
        Total=(Total+Sum*Power(Num,D-2))%D;
    }
    cout<<Total;
}