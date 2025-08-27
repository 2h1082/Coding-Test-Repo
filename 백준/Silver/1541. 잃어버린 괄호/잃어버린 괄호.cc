#include <iostream>
#include <sstream>

using namespace std;
int main()
{
    string Text;
    cin>>Text;
    stringstream ss(Text);
    int Num=0, Sum=0;
    bool bIsMinus=false;
    char T;
    ss>>Sum;
    while(ss>>T>>Num)
    {
        if(T=='-') bIsMinus=true;
        if(bIsMinus)
        {
            Sum-=Num;
        }
        else
        {
            Sum+=Num;
        }
    }
    cout<<Sum;
}