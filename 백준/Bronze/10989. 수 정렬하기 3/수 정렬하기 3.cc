#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;
int main()
{
    int N=0;
    cin>>N;
    vector<int> Nums(10001,0);
    for(int i=0;i<N;++i)
    {
        int Num=0;
        cin>>Num;
        Nums[Num]++;
    }
    for(int i=1;i<10001;++i)
    {
        if(Nums[i]==0) continue;
        for(int j=0;j<Nums[i];++j) cout<<i<<"\n";
    }
}