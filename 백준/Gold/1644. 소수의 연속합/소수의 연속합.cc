#include <iostream>
#include <numeric>
#include <vector>

using namespace std;

int main()
{
    int N=0;
    cin>>N;
    vector<bool> Primes(N+1,true);
    vector<long long> Nums;
    for (int i=2;i*i<=N;++i)
    {
        if (Primes[i])
        {
            for (int j=i*2;j<=N;j+=i)
            {
                Primes[j]=false;
            }
        }
    }

    for (int i=2;i<=N;++i)
    {
        if (Primes[i])
        {
            Nums.push_back(i);
        }
    }
    int Cnt=0, L=0;
    long long Sum=0;
    for (int R=0;R<Nums.size();++R)
    {
        Sum+=Nums[R];
        while (Sum>=N)
        {
            if (Sum==N)
            {
                Cnt++;
            }
            Sum-=Nums[L++];
        }
    }
    cout<<Cnt;
}