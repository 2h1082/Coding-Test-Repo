#include <iostream>

using namespace std;
int main()
{
    int N=0, Sum=0;;
    string Nums;
    cin>>N>>Nums;
    
    for(int i=0;i<N;++i)
    {
        Sum+=Nums[i]-'0';
    }
    cout<<Sum;
}