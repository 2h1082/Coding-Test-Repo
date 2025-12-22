#include "bits/stdc++.h"
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    int N;
    cin>>N;
    
    vector<int> H(N,0);
    for(auto& h : H) cin>>h;
    
    int Min=1e9;
    for(int Low=1;Low<=83;++Low)
    {
        int CurCost=0;
        int High=Low+17;
        
        for(int i=0;i<N;++i)
        {
            if(H[i] < Low)
            {
                int Diff=Low-H[i];
                CurCost+=Diff*Diff;
            }
            else if(H[i] > High)
            {
                int Diff=H[i]-High;
                CurCost+=Diff*Diff;
            }
        }
        Min=min(Min,CurCost);
    }
    cout<<Min;
}