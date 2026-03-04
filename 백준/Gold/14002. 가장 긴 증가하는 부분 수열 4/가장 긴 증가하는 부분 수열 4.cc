#include "bits/stdc++.h"
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    
    int N;
    cin>>N;
    vector<int> A(N), LIS, Pos(N,-1);
    for(auto& a : A) cin>>a;
    
    for(int i=0;i<N;++i)
    {
        if(!LIS.empty() && LIS.back() >= A[i])
        {
            auto It=lower_bound(LIS.begin(),LIS.end(),A[i]);
            *It=A[i];
            Pos[i]=It-LIS.begin();
        }
        else
        {
            Pos[i]=LIS.size();
            LIS.push_back(A[i]);
        }
    }
    int Len=LIS.size();
    cout<<Len<<'\n';
    
    int Target=Len-1;
    vector<int> Ans;
    for(int i=N-1;i>=0;--i)
    {
        if(Target==Pos[i])
        {
             Ans.push_back(A[i]);
            --Target;
        }
    }
    for(auto It=Ans.rbegin();It!=Ans.rend();++It) cout<<*It<<' ';
}