#include <iostream>
#include <vector>

using namespace std;
int main()
{
    int cnt=0;
    while(1)
    {
        string s;
        cin>>s;
        if(s.empty()) break;
        ++cnt;
    }
    cout<<cnt;
}