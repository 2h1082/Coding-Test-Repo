#include <iostream>

using namespace std;
int main()
{
    int L=0;
    string Text;
    cin>>L>>Text;
    
    long long Hash=0, R=1;
    for(int i=0;i<L;++i)
    {
        int Alpha=Text[i]-'a'+1;
        Hash=(Hash+Alpha*R)%1234567891;
        R=R*31%1234567891;
    }
    cout<<Hash;
}