#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
int N=0;
vector<int> Nums;
int Max=0;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    cin>>N;
    Nums.assign(N,0);
    for(int i=0;i<N;++i)
    {
        cin>>Nums[i];
    }
    vector<int> DP(N,1);
    for(int i=0;i<N;++i)
    {
        for(int j=i+1;j<N;++j)
        {
            if(Nums[j]>Nums[i])
            {
                DP[j]=max(DP[j],DP[i]+1);
            }
        }
    }
    Max=*max_element(DP.begin(),DP.end());
    cout<<Max;
}