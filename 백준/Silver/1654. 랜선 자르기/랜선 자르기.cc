#include <iostream>
#include <vector>
#include <climits>

using namespace std;
int main()
{
    int K=0,N=0;
    cin>>K>>N;
    vector<long long> Length(K,0);   
    long long Low=1, High=INT_MIN;
    for(int i=0;i<K;++i)
    {
        cin>>Length[i];
        High=max(Length[i],High);
    }
    long long Result=0;
    while(Low<=High)
    {
        long long Mid=(Low+High)/2;
        int Count=0;
        for(auto& L:Length)
        {
            Count+=L/Mid;
        }
        if(Count<N)
        {
            High=Mid-1;
        }
        else
        {
            Result=Mid;
            Low=Mid+1;
        }
    }
    cout<<Result;
}
