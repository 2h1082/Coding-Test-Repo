#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>

using namespace std;
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int N=0;
    cin>>N;
    if(N==0)
    {
        cout<<"0";
        return 0;
    }
    vector<int> Nums(N);
    for(int i=0;i<N;++i)
    {
        cin>>Nums[i];
    }
    sort(Nums.begin(),Nums.end());
    float Except=0.15f*N;
    Except=round(Except);
    float Avg=0;
    for(int i=Except;i<N-Except;++i)
    {
        Avg+=Nums[i];
    }
    Avg/=(N-2*Except);
    cout<<round(Avg);
}