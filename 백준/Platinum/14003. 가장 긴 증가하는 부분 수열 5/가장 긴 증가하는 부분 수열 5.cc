#include <bits/stdc++.h>

using namespace std;

int main()
{
    int N=0;
    cin>>N;
    vector<int> Nums(N,0);
    vector<int> LCS;
    vector<int> Length(N,0);
    for(auto& Num:Nums)
    {
        cin>>Num;
    }
    for(int i=0;i<N;++i)
    {
        if(LCS.empty()||LCS.back()<Nums[i])
        {
           LCS.push_back(Nums[i]); 
           Length[i]=LCS.size();
        }
        else
        {
            auto Start=lower_bound(LCS.begin(),LCS.end(),Nums[i]);
            *Start=Nums[i];
            Length[i]=(Start-LCS.begin())+1;
        }
    }
    
    int Target=LCS.size(), LastNum=INT_MAX;
    vector<int> Res;
    for(int i=N-1;i>=0;--i)
    {
        if(Length[i]==Target&&Nums[i]<LastNum)
        {
            Res.push_back(Nums[i]);
            LastNum=Nums[i];
            Target--;
        }
    }
    cout<<LCS.size()<<"\n";
    reverse(Res.begin(),Res.end());
    for(auto& Num : Res)
    {
        cout<<Num<<" ";
    }
}