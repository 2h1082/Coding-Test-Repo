#include <iostream>

using namespace std;

bool IsPrimeNum(int Num)
{
    if(Num==1) return false;
    if(Num==2||Num==3) return true;
    if(Num%2==0||Num%3==0) return false;
    
    for(int i=5;i*i<=Num;i+=6)
    {
        if(Num%i==0||Num%(i+2)==0)
        {
            return false;
        }
    }
    return true;
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int M,N;
    cin>>M>>N;
    for(int i=M;i<=N;++i)
    {
        if(IsPrimeNum(i)) cout<<i<<"\n";
    }
}