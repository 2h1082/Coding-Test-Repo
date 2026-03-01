#include "bits/stdc++.h"
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    
    int N;
    cin>>N;
    vector<int> Ans;
    for(int i=0;i<N;++i)
    {
        int Cur;
        cin>>Cur;
        if(!Ans.empty() && Ans.back() >= Cur)
        {
            auto It=lower_bound(Ans.begin(),Ans.end(),Cur);
            *It=Cur;
        }
        else
        {
            Ans.push_back(Cur);
        }
    }
    cout<<Ans.size();
}