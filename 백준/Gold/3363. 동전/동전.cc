#include "bits/stdc++.h"
using namespace std;

struct Info
{
    int L[4], R[4], Cmp=0;
};
int main()
{
    vector<Info> W(3);
    for(int i=0;i<3;++i)
    {
        for(int j=0;j<4;++j) cin>>W[i].L[j];
        
        char Cmp;
        cin>>Cmp;
        W[i].Cmp = (Cmp == '>') ? 1 : (Cmp == '<') ? -1 : 0;
        
        for(int j=0;j<4;++j) cin>>W[i].R[j];
    }
    
    vector<pair<int,int>> Ans;
    for(int i=1;i<13;++i)
    {
        for(int State : {-1,1})
        {
            vector<int> Coin(13,0);
            Coin[i]=State;
            bool bIsOk=true;
            
            for(int k=0;k<3;++k)
            {
                int SumL=0, SumR=0;
                for(int j=0;j<4;++j)
                {
                    SumL+=Coin[W[k].L[j]];
                    SumR+=Coin[W[k].R[j]];
                }
                
                if(W[k].Cmp == -1 && SumL>=SumR)     bIsOk=false;
                else if(W[k].Cmp == 1 && SumL<=SumR)  bIsOk=false;
                else if(W[k].Cmp == 0 && SumL!=SumR) bIsOk=false;
            }
            if(bIsOk) Ans.push_back({i, State});
        }
    }
    if(Ans.empty())       cout<<"impossible";
    else if(Ans.size()>1) cout<<"indefinite";
    else                  cout<<Ans.back().first<<(Ans.back().second==-1 ? '-' : '+');
    
}