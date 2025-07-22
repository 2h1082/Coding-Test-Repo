#include <iostream>
#include <vector>

using namespace std;
int main()
{
    vector<int> Nums(8);
    
    for(int i=0;i<8;++i)
    {
        cin>>Nums[i];
    }
    
    string Result="mixed";
    
    bool bIsAscending=false;
    if(Nums[0]==1) bIsAscending=true;
    else if(Nums[0]==8) bIsAscending=false;
    else
    {
        cout<<Result;
        return 0;
    }
    
    bool bIsSuccess=true;
    for(int i=0;i<8;++i)
    {
        int Checker = bIsAscending ? i+1 : 8-i;
        if(Checker!=Nums[i]) 
        {
            bIsSuccess=false;
            break;
        }
    }
    if(bIsSuccess)
    {
        Result= bIsAscending ? "ascending" : "descending";
    }
    cout<<Result;
}