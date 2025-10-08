#include <bits/stdc++.h>

using namespace std;

int main()
{
    int N=0;
    cin>>N;
    vector<vector<int>> Adj(N,vector<int>(N,0));
    int Min=INT_MAX;
    
    for(auto& R : Adj)
    {
        for(auto& C : R)
        {
            cin>>C;
        }
    }
    for(int Start=0;Start<N;++Start)
    {
        vector<vector<int>> DP((1<<N),vector<int>(N,INT_MAX));
        DP[1<<Start][Start]=0;
        for(int Mask=0;Mask<(1<<N);++Mask)
        {
            for(int Cur=0;Cur<N;++Cur)
            {
                if(!(Mask&(1<<Cur))) continue;
                for(int Next=0;Next<N;++Next)
                {
                    if(Cur==Next||Mask&(1<<Next)||!Adj[Cur][Next]||DP[Mask][Cur]==INT_MAX) continue;
                    int NewMask=Mask|(1<<Next);
                    DP[NewMask][Next]=min(DP[NewMask][Next],DP[Mask][Cur]+Adj[Cur][Next]);
                }
            }
        }
        int FullMask=(1<<N)-1;
        for(int End=0;End<N;++End)
        {
            if(End==Start||!Adj[End][Start]||DP[FullMask][End]==INT_MAX) continue;
            Min=min(Min,DP[FullMask][End]+Adj[End][Start]);
        }
    }
    
    cout<<Min;
}