#include <iostream>

using namespace std;
int main()
{
    int N=0;
    cin>>N;
    char Grade;
    
    if(N>=90)      Grade='A';
    else if(N>=80) Grade='B';
    else if(N>=70) Grade='C';
    else if(N>=60) Grade='D';
    else           Grade='F';
    
    cout<<Grade;
}