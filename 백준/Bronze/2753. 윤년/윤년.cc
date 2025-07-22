#include <iostream>

using namespace std;
int main()
{
    int N=0;
    cin>>N;
    int R=0;
    if(N%400==0 || (N%4==0 && N%100!=0)) R=1;
    cout<<R;
}