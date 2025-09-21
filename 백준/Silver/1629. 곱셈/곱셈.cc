#include <iostream>
#include <vector>

using namespace std;
int Power(int& A, int B, int& C)
{
    if(B==1)
    {
        return A%C;
    }
    long long Num=Power(A,B/2,C);
    Num=Num*Num%C;
    if(B%2)
    {
        return Num*A%C;
    }
    else
    {
        return Num;
    }
}
int main()
{
    int A,B,C;
    cin>>A>>B>>C;
    
    cout<<Power(A,B,C);
}