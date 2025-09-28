#include <iostream>
#include <vector>

using namespace std;
int main()
{
    int N=0;
    cin>>N;
    vector<int> Nums(N,0);
    vector<int> Up(N,0), Down(N,0);
    for(int i=0;i<N;++i)
    {
        cin>>Nums[i];
    }
    for(int i=0;i<N;++i)
    {
        for(int j=i+1;j<N;++j)
        {
            if(Nums[j]>Nums[i])
            {
                Up[j]=max(Up[j],Up[i]+1);
            }
            if(Nums[N-j-1]>Nums[N-i-1])
            {
                Down[N-j-1]=max(Down[N-j-1],Down[N-i-1]+1);
            }
        }
    }
    int Max=0;
    for(int i=0;i<N;++i)
    {
        Max=max(Max,Up[i]+Down[i]+1);
    }
    cout<<Max;
}
