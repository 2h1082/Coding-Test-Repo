#include <iostream>
#include <vector>

using namespace std;
int main()
{
    vector<int> Num(5);
    int Sum=0;
    for(int i=0;i<Num.size();++i)
    {
        cin>>Num[i];
        Sum+=Num[i]*Num[i];
    }
    cout<<Sum%10;
}