#include <iostream>
#include <vector>
#include <map>
#include <algorithm>

using namespace std;
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int N=0;
    cin>>N;
    vector<int> X(N);
    map<int,vector<int>> Index;
    vector<int> Rank(N);
    for(int i=0;i<N;++i)
    {
        cin>>X[i];
        Index[X[i]].push_back(i);
    }
    sort(X.begin(),X.end());
    auto last=unique(X.begin(),X.end());
    X.erase(last,X.end());
    for(int i=0;i<X.size();++i)
    {
        for(auto& I:Index[X[i]])
        {
            Rank[I]=i;            
        }
    }
    for(auto& Temp:Rank)
    {
        cout<<Temp<<" ";
    }
}