#include "bits/stdc++.h"
using namespace std;

struct Node
{
    string S;
    int Sum=0;
    
    bool operator < (const Node& other)
    {
        if(S.length() != other.S.length()) return S.length() < other.S.length();
        if(Sum != other.Sum)               return Sum < other.Sum;
        return S < other.S;
    }
};
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    
    int N;
    cin>>N;
    
    vector<Node> A(N);
    for(auto& a : A) 
    {
        cin>>a.S;
        for(auto& c:a.S)
        {
            if(c>='0' && c<='9') a.Sum+=c-'0';
        }
    }
    sort(A.begin(),A.end());
    for(auto& a : A) cout<<a.S<<'\n';
}