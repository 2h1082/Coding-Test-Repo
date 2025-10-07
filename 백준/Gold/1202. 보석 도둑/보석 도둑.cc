#include <bits/stdc++.h>
using namespace std;

int main()
{
    int N,K;
    cin>>N>>K;
    vector<int> Bag(K,0);
    vector<pair<int,int>> Jw(N);
    priority_queue<int> pq;
    for(int i=0;i<N;++i)
    {
        cin>>Jw[i].first>>Jw[i].second;
    }
    for(int i=0;i<K;++i)
    {
        cin>>Bag[i];
    }
    sort(Bag.begin(),Bag.end());
    sort(Jw.begin(),Jw.end());
    long long Sum=0;
    int Idx=0;
    for(auto& B : Bag)
    {
        while(Idx<N&&Jw[Idx].first<=B)
        {
            pq.push(Jw[Idx].second);
            Idx++;
        }
        if(!pq.empty())
        {
            Sum+=(long long)pq.top();
            pq.pop();
        }
    }
    cout<<Sum;
}