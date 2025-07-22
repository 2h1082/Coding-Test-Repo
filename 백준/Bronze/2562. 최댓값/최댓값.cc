#include <iostream>
#include <vector>

using namespace std;
int main()
{
    vector<int> Nums(9);
    int MaxIdx=0;
    for(int i=0;i<9;++i)
    {
        cin>>Nums[i];
        MaxIdx = Nums[MaxIdx]<Nums[i] ? i : MaxIdx;
    }
    cout<<Nums[MaxIdx]<<"\n"<<MaxIdx+1;
}