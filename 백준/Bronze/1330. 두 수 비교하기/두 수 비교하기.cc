#include <iostream>

using namespace std;
int main()
{
    int a=0, b=0;
    
    cin>>a>>b;
    string c="";
    if(a>b)
    {
        c=">";
    }
    else if(a<b)
    {
        c="<";
    }
    else 
    {
        c="==";
    }
    cout<<c;
}