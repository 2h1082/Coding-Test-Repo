#include "bits/stdc++.h"
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    
    while(1)
    {
        vector<int> L(3,0);
        cin>>L[0]>>L[1]>>L[2];
        sort(L.begin(),L.end());
        if(L[0]==0 && L[1]==0 && L[2]==0) break;
        
        if(L[2]>=L[0]+L[1]) 
        {
            cout<<"Invalid\n";
            continue;
        }
        bool bIsEqualAB=(L[0]==L[1]), bIsEqualBC=(L[1]==L[2]), bIsEqualAC=(L[0]==L[2]); 
        string Ans;
        if(bIsEqualAB && bIsEqualBC && bIsEqualAC)      Ans="Equilateral\n";
        else if(bIsEqualAB || bIsEqualBC || bIsEqualAC) Ans="Isosceles\n";
        else                                            Ans="Scalene\n";
        cout<<Ans;
    }
}