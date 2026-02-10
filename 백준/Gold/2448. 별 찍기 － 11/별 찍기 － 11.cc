#include "bits/stdc++.h"
using namespace std;

vector<string> Ans;
void Print(int R, int C, int Size)
{
    if(Size==3)
    {
        Ans[R][C]=Ans[R+1][C-1]=Ans[R+1][C+1]=Ans[R+2][C-2]=Ans[R+2][C-1]=Ans[R+2][C]=Ans[R+2][C+1]=Ans[R+2][C+2]='*';
        return;
    }
    int NxtSize=Size/2;
    Print(R,C,NxtSize);
    Print(R+NxtSize,C-NxtSize,NxtSize);
    Print(R+NxtSize,C+NxtSize,NxtSize);
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    
    int N=0;
    cin>>N;
    int Len=2*N-1;
    Ans.assign(N,string(Len,' '));
    Print(0,Len/2,N);
    for(auto& r : Ans)
    {
        for(auto& c : r)
        {
            cout<<c;
        }
        cout<<'\n';
    }
}