#include <iomanip>
#include <iostream>
#include <vector>

using namespace std;
int main()
{
    int A,B,V;
    cin>>A>>B>>V;
    int Day=1, Divisor=A-B;

    Day+=(V-A+Divisor-1)/Divisor;
    cout<<Day;
}