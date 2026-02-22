#include "bits/stdc++.h"
using namespace std;

struct Info
{
    string Name;
    int K, E, M;
    bool operator < (const Info& other)
    {
        if(K!=other.K) return K > other.K;
        if(E!=other.E) return E < other.E;
        if(M!=other.M) return M > other.M;
        return Name < other.Name;
    }
};
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    
    int N;
    cin>>N;
    vector<Info> A(N);
    for(auto& [S, K, E, M]:A) cin>>S>>K>>E>>M;
    sort(A.begin(),A.end());
    for(auto& [S, K, E, M]:A) cout<<S<<'\n';
}