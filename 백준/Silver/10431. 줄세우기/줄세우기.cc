#include "bits/stdc++.h"
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    int P;
    cin>>P;
    for(int i=1;i<=P;++i)
    {
        int Temp=0;
        cin>>Temp;
        cout<<i<<' ';
        vector<int> Num;
        int Cnt=0;
        for(int j=0;j<20;++j)
        {
            int New;
            cin>>New;
            Cnt+=count_if(Num.begin(),Num.end(),[&](int x){
                return x>New;
            });
            Num.push_back(New);
        }
        
        cout<<Cnt<<'\n';
    }
}