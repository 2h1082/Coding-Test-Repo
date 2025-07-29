#include <iomanip>
#include <iostream>
#include <vector>

using namespace std;
int main()
{
    int N=0;
    cin>>N;
    vector<float> A(N);
    float Max=0;
    for (int i=0;i<N;++i)
    {
        cin>>A[i];
        Max=max(Max,A[i]);
    }
    float Avg=0;
    for (int i=0;i<N;++i)
    {
        A[i]=A[i]/Max*100;
        Avg+=A[i];
    }
    cout<<fixed<<setprecision(2)<<Avg/N;
}