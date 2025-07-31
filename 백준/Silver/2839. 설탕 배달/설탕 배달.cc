#include <iostream>
#include <climits>

using namespace std;
int main()
{
    int N=0;
    cin>>N;
    
    int Min=INT_MAX;
    for (int i=0;i<=N/5;++i)
    {
        int CurWeight=N-(i*5);
        if(CurWeight%3==0)
        {
            int CurCount=i+CurWeight/3;
            Min=min(Min,CurCount);
        }
    }
    int Result=Min==INT_MAX?-1:Min;
    cout<<Result;
}