#include "bits/stdc++.h"
using namespace std;

vector<string> Ans;
void Print(int R, int C, int Size)
{
    if(Size==3)
    {
        Ans[R][C]=Ans[R][C+1]=Ans[R][C+2]=Ans[R+1][C]=Ans[R+1][C+2]=Ans[R+2][C]=Ans[R+2][C+1]=Ans[R+2][C+2]='*';
        return;
    }
    int NxtSize=Size/3;
    for(int i=0;i<Size;i+=NxtSize)
    {
        for(int j=0;j<Size;j+=NxtSize)
        {
            if(i==NxtSize && j==NxtSize) continue;
            Print(R+i,C+j,NxtSize);
        }
    }
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    
    int N;
    cin>>N;
    
    Ans.assign(N,string(N,' '));
    Print(0,0,N);
    for (const auto& s : Ans) cout<<s<<'\n';
}