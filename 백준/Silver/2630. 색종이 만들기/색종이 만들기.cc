#include "bits/stdc++.h"
using namespace std;

int N;
vector<vector<int>> A;
vector<int> Cnt(2,0);
void Count(int R, int C, int Size)
{
    int Base=A[R][C];
    if(Size==1)
    {
        ++Cnt[Base];
        return;
    }
    bool bShouldDivide=false;
    for(int i=R;i<R+Size;++i)
    {
        for(int j=C;j<C+Size;++j)
        {
            if(Base==A[i][j]) continue;
            bShouldDivide=true;
            break;
        }
        if(bShouldDivide) break;
    }
    if(!bShouldDivide)
    {
        ++Cnt[Base];
        return;
    }
    int NxtSize=Size/2;
    for(int i=0;i<Size;i+=NxtSize)
    {
        for(int j=0;j<Size;j+=NxtSize)
        {
            Count(R+i,C+j,NxtSize);
        }
    }
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    
    cin>>N;
    A.assign(N,vector<int>(N,0));
    for(int i=0;i<N;++i)
    {
        for(int j=0;j<N;++j)
        {
            cin>>A[i][j];
        }
    }
    Count(0,0,N);
    for(int c : Cnt) cout<<c<<'\n';
}