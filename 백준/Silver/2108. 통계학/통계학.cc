#include <iostream>
#include <vector>
#include <map>
#include <algorithm>
#include <numeric>
#include <queue>
#include <cmath>

using namespace std;
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int N=0;
    cin>>N;
    vector<int> V(N);
    map<int,int> Rate;
    int MaxCount=0;
    for(int i=0;i<N;++i)
    {
        cin>>V[i];
        Rate[V[i]]++;
        MaxCount=max(MaxCount,Rate[V[i]]);
    }
    sort(V.begin(),V.end());
    float Avg=accumulate(V.begin(),V.end(),0);
    Avg/=N;
    int Mid=V[V.size()/2];
    int Range=V.size()>1?V[V.size()-1]-V[0]:0;
    int Mode=0;
    priority_queue<int,vector<int>,greater<>> pq;
    for(auto& It:Rate)
    {
        if(MaxCount==It.second)
        {
            pq.push(It.first);
        }
    }
    if (pq.size()>1) pq.pop();
    Mode=pq.top();
    cout<<(int)round(Avg)<<"\n"<<Mid<<"\n"<<Mode<<"\n"<<Range;
}