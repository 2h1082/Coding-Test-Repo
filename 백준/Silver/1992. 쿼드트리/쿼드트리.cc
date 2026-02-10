#include "bits/stdc++.h"
using namespace std;

vector<string> A;
void Compress(int R, int C, int Size)
{
    char Base=A[R][C];
    if(Size==1)
    {
        cout<<Base;
        return;
    }
    bool bIsEqual=true;
    for(int i=R;i<R+Size;++i)
    {
        for(int j=C;j<C+Size;++j)
        {
            if(Base!=A[i][j])
            {
                bIsEqual=false;
                break;
            }
        }
        if(!bIsEqual) break;
    }
    if(bIsEqual)
    {
        cout<<Base;
        return;
    }
    cout<<'(';
    int NxtSize=Size/2;
    for(int i=0;i<Size;i+=NxtSize)
    {
        for(int j=0;j<Size;j+=NxtSize)
        {
            Compress(R+i,C+j,NxtSize);
        }
    }
    cout<<')';
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    
    int N;
    cin>>N;
    
    A.resize(N);
    for(auto& a : A) cin>>a;
    Compress(0,0,N);
}