#include <bits/stdc++.h>
using namespace std;
using ll=long long;
int N, M, K;
vector<vector<ll>> Mul(vector<vector<int>>& A, vector<vector<int>>& B)
{
    vector<vector<ll>> Res(N,vector<ll>(K,0));
    for(int i=0;i<N;++i)
    {
        for(int k=0;k<M;++k)
        {
            for(int j=0;j<K;++j)
            {
                Res[i][j]+=1LL*A[i][k]*B[k][j];
            }
        }
    }
    return Res;
}
int main()
{
    cin>>N>>M;
    
    vector<vector<int>> A, B;
    A.assign(N,vector<int>(M,0));
    for(auto& r : A)
        for(auto& c  : r)
            cin>>c;
    
    cin>>M>>K;
    B.assign(M,vector<int>(K,0));
    for(auto& r : B)
        for(auto& c  : r)
            cin>>c;
    
    vector<vector<ll>> Res=Mul(A,B);
    
    for(auto& r : Res)
    {
        for(auto& c : r)
        {
            cout<<c<<' ';
        }
        cout<<'\n';
    }
}