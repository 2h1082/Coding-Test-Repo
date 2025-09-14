#include <iostream>

using namespace std;


int main()
{
    int N=0,R=0,C=0;
    cin>>N>>R>>C;
    int N2=1;
    while(N--)
    {
        N2=N2<<1;
    }
    int Count=0;
    while(N2>1)
    {
        N2/=2;
        int BlockCount=N2*N2;
        int ColBlock=C/N2;
        int RowBlock=R/N2;
        C%=N2;
        R%=N2;
        Count+=((RowBlock*2)+ColBlock)*BlockCount;
    }
    cout<<Count;
}

