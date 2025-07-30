#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
int main()
{
    int N=0;
    cin>>N;
    
    long long Divisor=5;
    int Count=0;
    while(Divisor<=N)
    {
        Count+=N/Divisor;
        Divisor*=5;
    }
    cout<<Count;
}
