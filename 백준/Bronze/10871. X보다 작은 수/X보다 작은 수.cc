#include <iostream>
#include <vector>

using namespace std;
int main()
{
    int N=0, X=0;
    cin>>N>>X;
    
    for(int i=0;i<N;++i)
    {
        int Temp=0;
        cin>>Temp;
        if(Temp<X) cout<<Temp<<" ";
    }
}