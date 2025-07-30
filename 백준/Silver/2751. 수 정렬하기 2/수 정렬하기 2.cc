#include <iostream>
#include <set>
#include <algorithm>

using namespace std;
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int N=0;
    cin>>N;
    set<int> Nums;
    for(int i=0;i<N;++i)
    {
        int Temp=0;
        cin>>Temp;
        Nums.insert(Temp);
    }
    for(auto& Num : Nums)
    {
        cout<<Num<<"\n";
    }
}
