#include <iomanip>
#include <iostream>
#include <vector>

using namespace std;
int main()
{
    int N,K;
    cin >> N >> K;

    int Answer=1;
    int Divisor=1;
    for (int i=1;i<=K;++i)
    {
        Answer*=N-i+1;
        Divisor*=i;
    }
    cout<<Answer/Divisor;
}