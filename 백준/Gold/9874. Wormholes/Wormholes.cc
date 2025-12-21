#include "bits/stdc++.h"
using namespace std;
vector<pair<int,int>> A;
vector<int> NextWormhole, Partner;
int N;

bool IsLoop()
{
    for(int s=0;s<N;++s)
    {
        int Pos=s;
        for(int Step=0;Step<N;++Step)
        {
            Pos=NextWormhole[Partner[Pos]];
            if(Pos==-1) break;
            if(Pos==s)  return true;
        }
    }
    return false;
}
int DFS()
{
    int F=-1;
    for(int i=0;i<N;++i)
    {
        if(Partner[i]==-1)
        {
            F=i;
            break;
        }
    }
    if(F==-1)
    {
        return IsLoop();
    }
    
    int Cnt=0;
    for(int j=F+1;j<N;++j)
    {
        if(Partner[j]==-1)
        {
            Partner[j]=F;
            Partner[F]=j;
            Cnt+=DFS();
            Partner[j]=Partner[F]=-1;
        }
    }
    return Cnt;
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    cin>>N;
    A.resize(N);
    NextWormhole.assign(N,-1);
    Partner.assign(N,-1);
    for(auto& [y, x] : A) cin>>x>>y;
    
    for(int i=0;i<N;++i)
    {
        int ClosestX=-1;
        for(int j=0;j<N;++j)
        {
            if((A[i].first==A[j].first && A[j].second > A[i].second)
               && (ClosestX==-1 || A[j].second < A[ClosestX].second))
            {
                ClosestX=j;
            }
        }
        NextWormhole[i]=(ClosestX==-1) ? -1 : ClosestX;
    }
    cout<<DFS();
}