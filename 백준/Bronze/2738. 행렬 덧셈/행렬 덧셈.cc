#include <bits/stdc++.h>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int N,M;
    cin>>N>>M;
    
    vector<vector<int>> M1(N,vector<int>(M,0)), M2(N,vector<int>(M,0));
    for(int i=0;i<N;++i)
    {
        for(int j=0;j<M;++j)
        {
            cin>>M1[i][j];
        }
    }
    for(int i=0;i<N;++i)
    {
        for(int j=0;j<M;++j)
        {
            cin>>M2[i][j];
            M1[i][j]+=M2[i][j];
        }
    }
    for(int i=0;i<N;++i)
    {
        for(int j=0;j<M;++j)
        {
            cout<<M1[i][j]<<" ";
        }
        cout<<"\n";
    }
}