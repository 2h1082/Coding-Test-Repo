#include <bits/stdc++.h>

using namespace std;

const int MaxVal=1000000;
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    int N=0;
    cin>>N;
    vector<int> Cards(N,0);
    vector<int> Owner(MaxVal+1,-1);
    for(int i=0;i<N;++i)
    {
        cin>>Cards[i];
        Owner[Cards[i]]=i;
    }
    vector<int> Score(N,0);
    for(int i=1;i<=MaxVal;++i)
    {
        if(Owner[i]==-1) continue;
        for(int Multiple=2*i;Multiple<=MaxVal;Multiple+=i)
        {
            if(Owner[Multiple]!=-1)
            {
                Score[Owner[i]]++;
                Score[Owner[Multiple]]--;
            }
        }
    }
    for(auto& S : Score)
    {
        cout<<S<<" ";
    }
}