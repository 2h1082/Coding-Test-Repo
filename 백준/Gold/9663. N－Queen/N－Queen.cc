#include <iostream>
#include <vector>

using namespace std;
int N=0, Solution=0;
vector<bool> Col, Diag1, Diag2;

void NQueen(int Y)
{
    if(Y==N)
    {
        Solution++;
        return;
    }
    for (int i=0;i<N;++i)
    {
        if(Col[i]||Diag1[Y-i+N-1]||Diag2[Y+i]) continue;
        Col[i]=true;
        Diag1[Y-i+N-1]=true;
        Diag2[Y+i]=true;
        NQueen(Y+1);
        Col[i]=false;
        Diag1[Y-i+N-1]=false;
        Diag2[Y+i]=false;
    }
}
int main()
{
    cin>>N;
    Col.assign(N,false);
    Diag1.assign(2*N-1,false);
    Diag2.assign(2*N-1,false);
    
    NQueen(0);
    cout<<Solution;
}