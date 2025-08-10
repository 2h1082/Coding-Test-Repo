#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>

using namespace std;
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int N=0;
    cin>>N;
    vector<int> V(N);
    for(int i=0;i<N;++i)
    {
        cin>>V[i];
    }
    sort(V.begin(),V.end());
    vector<int> Sum=V;
    for(int i=1;i<N;++i)
    {
        Sum[i]+=Sum[i-1];
    }
    int Total=accumulate(Sum.begin(),Sum.end(),0);
    cout<<Total<<"\n";
}