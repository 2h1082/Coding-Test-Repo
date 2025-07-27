#include <iostream>

using namespace std;
int main()
{
    int N=0;
    cin>>N;
    
    int Count=1;
    for(int i=1;1<N;++i)
    {
        N-=6*i;
        Count++;
    }
    cout<<Count;
}