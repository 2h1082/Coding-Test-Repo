#include "bits/stdc++.h"
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    
    int N,K, Ans=0;
    cin>>N>>K;
    
    vector<vector<int>> Room(2,vector<int>(7,0));
    while(N--)
    {
        int S, Y;
        cin>>S>>Y;
        
        Room[S][Y]++;
        if(Room[S][Y]==1) ++Ans;
        if(Room[S][Y]==K) Room[S][Y]=0;
    }
    cout<<Ans;
}