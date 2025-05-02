#include <iostream>
#include <numeric>
#include <queue>
#include <vector>

using namespace std;
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    int n=0;
    cin>>n;
    vector<long long> SumN(n+1,0);
    for (int i=1;i<=n;i++)
    {
        for (int j=i;j<=n;j+=i)
        {
            SumN[j]+=i;
        }
    }
    long long answer=accumulate(SumN.begin(),SumN.end(),0LL);
    cout<<answer;
    return 0;
}