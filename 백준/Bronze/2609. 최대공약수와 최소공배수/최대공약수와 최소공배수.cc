#include <iomanip>
#include <iostream>
#include <vector>

using namespace std;

int GCD(int a, int b)
{
    while(b>0)
    {
        int Temp=a%b;
        a=b;
        b=Temp;
    }
    return a;
}

int LCM(int a, int b)
{
    return a*b/GCD(a,b);
}

int main()
{
    int A,B;
    cin>>A>>B;
    
    int Result1=GCD(A,B);
    int Result2=LCM(A,B);
    cout<<Result1<<endl<<Result2;
}