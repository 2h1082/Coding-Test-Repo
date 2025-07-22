#include <iostream>
#include <vector>

using namespace std;
int main()
{
    int T=0;
    vector<int> Num(2);
    cin>>T;
    for(int i=0;i<T;++i)
    {
        int H,W,N;
        cin>>H>>W>>N;
        
        Num[0]=(N%H == 0) ? H : N%H;
        Num[1]=(N-1)/H+1;
        
        cout<<Num[0];
        if(Num[1]<10) cout<<"0";
        cout<<Num[1]<<"\n";
    }
}