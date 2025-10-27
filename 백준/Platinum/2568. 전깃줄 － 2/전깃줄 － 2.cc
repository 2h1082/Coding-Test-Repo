#include <bits/stdc++.h>

using namespace std;

int main()
{
    int N=0;
    cin>>N;
    vector<pair<int,int>> A(N);
    for(int i=0;i<N;++i)
    {
        cin>>A[i].first>>A[i].second;
    }
    sort(A.begin(),A.end());
    
    vector<int> LIS, Len(N,0);
    for(int i=0;i<N;++i)
    {
        if(LIS.empty()||LIS.back()<A[i].second)
        {
            LIS.push_back(A[i].second);
            Len[i]=LIS.size();
        }
        else
        {
            auto Start=lower_bound(LIS.begin(),LIS.end(),A[i].second);
            *Start=A[i].second;
            Len[i]=Start-LIS.begin()+1;
        }
    }
    vector<int> Res;
    int TargetLen=LIS.size();
    int TargetNum=INT_MAX;
    for(int i=N-1;i>=0;--i)
    {
        if(TargetLen==Len[i]&&A[i].second<TargetNum)
        {
            TargetNum=A[i].second;
            TargetLen--;
        }
        else
        {
            Res.push_back(A[i].first);
        }
    }
    sort(Res.begin(),Res.end());
    
    cout<<Res.size()<<"\n";
    for(auto& r : Res)
    {
        cout<<r<<"\n";
    }
}