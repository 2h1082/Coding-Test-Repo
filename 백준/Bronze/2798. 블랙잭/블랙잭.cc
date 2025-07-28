#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
int main()
{
    int N=0, M=0;
    cin>>N>>M;
    
    vector<int> Cards(N,0);
    for(int i=0;i<N;++i)
    {
        cin>>Cards[i];
    }
    sort(Cards.begin(),Cards.end());
    
    int MaxSum=0;
    for(int i=0;i<N-2;++i)
    {
        for(int j=i+1;j<N-1;++j)
        {
            for(int k=j+1;k<N;++k)
            {
                int Sum=Cards[i]+Cards[j]+Cards[k];
                if(Sum<=M) MaxSum=max(MaxSum,Sum);
            }
        }
    }
    cout<<MaxSum;
}