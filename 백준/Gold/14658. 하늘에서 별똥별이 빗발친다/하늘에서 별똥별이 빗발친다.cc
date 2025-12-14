#include "bits/stdc++.h"
using namespace std;
#define x first
#define y second
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    int N,M,L,K;
    cin>>N>>M>>L>>K;

    vector<pair<int,int>> Dot(K);
    for(int i=0;i<K;++i) cin>>Dot[i].x>>Dot[i].y;
    
    int Max=0;
    for(const auto& Dot1 : Dot)
    {
        for(const auto& Dot2 : Dot)
        {
            int X=Dot1.x, Y=Dot2.y;
            int Cur=0;
            
            for(const auto& Dot3 : Dot)
            {
                bool InRangeX=(Dot3.x >= X) && (Dot3.x <= X+L);
                bool InRangeY=(Dot3.y >= Y) && (Dot3.y <= Y+L);
                if(InRangeX && InRangeY) Cur++;
            }
            Max=max(Max,Cur);
        }
    }
    cout<<K-Max;
}