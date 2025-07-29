#include <iostream>

using namespace std;
int main()
{
    while(1)
    {
        string Nums;
        cin>>Nums;
        if(Nums=="0") break;
        string Result="yes";
        int Len=Nums.size();
        for(int i=0;i<(Len/2);++i)
        {
            if(Nums[i]!=Nums[Len-i-1])
            {
                Result="no";
                break;
            }
        }   
        cout<<Result<<endl;
    }
}