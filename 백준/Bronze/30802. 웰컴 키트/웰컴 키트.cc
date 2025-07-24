#include <iostream>
#include <vector>

using namespace std;
int main()
{
    int N=0;
    cin>>N;
    vector<int> Shirts(6);
    
    for(int i=0;i<6;++i)
    {
        cin>>Shirts[i];
    }
    
    int T=0, P=0;
    cin>>T>>P;
    
    int GroupT=0, GroupP=0, SingleP=0;
    for(auto& Num : Shirts)
    {
        GroupT+=((Num-1+T)/T);
    }
    GroupP=N/P;
    SingleP=N%P;
    
    cout<<GroupT<<"\n"<<GroupP<<" "<<SingleP<<"\n";
}