#include <iostream>
#include <set>

using namespace std;
int main()
{
    set<int> Uniq;
    for(int i=0;i<10;++i)
    {
        int Temp=0;
        cin>>Temp;
        Uniq.insert(Temp%42);
    }
    cout<<Uniq.size();
}