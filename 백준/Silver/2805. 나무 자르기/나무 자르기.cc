#include <iostream>
#include <vector>
#include <climits>


using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int N=0,M=0;
    cin>>N>>M;
    vector<long long> H(N);
    long long L=0,R=INT_MIN, Result=0;
    while(N--)
    {
        cin>>H[N];
        R=max(R,H[N]);
    }
    while(L<=R)
    {
        long long Mid=(L+R)/2;
        long long Remain=0;
        for(auto& W:H)
        {
            if(W>Mid&&Mid>0)
            {
                Remain+=W-Mid;
            }
        }
        if(Remain>=M)
        {
            L=Mid+1;
            Result=Mid;
        }
        else
        {
            R=Mid-1;
        }
    }
    cout<<Result;
}