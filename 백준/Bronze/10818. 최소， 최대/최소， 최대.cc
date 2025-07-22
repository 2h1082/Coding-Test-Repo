#include <iostream>
#include <vector>
#include <climits>

using namespace std;
int main()
{
    int T=0;
    cin>>T;
    vector<int> Nums(T);
    int Max=INT_MIN, Min=INT_MAX;
    for(int i=0;i<T;++i)
    {
        cin>>Nums[i];
        if(Nums[i]>Max) Max=Nums[i];
        if(Nums[i]<Min) Min=Nums[i];
    }
    cout<<Min<<" "<<Max;
}