#include <vector>
#include <iostream>

using namespace std;
int ResultW=0,ResultB=0;
void Divide(vector<vector<int>>& P,int X, int Y,int N)
{
    int Pivot=P[Y][X];
    bool bShouldDivide=false;
    for(int i=0;i<N;++i)
    {
        for(int j=0;j<N;++j)
        {
            if(P[Y+i][X+j]!=Pivot)
            {
                bShouldDivide=true;
                break;
            }
        }
    }
    if(bShouldDivide&&N!=1)
    {
        int Offset=N/2;
        Divide(P,X,Y,Offset);
        Divide(P,X,Y+Offset,Offset);
        Divide(P,X+Offset,Y,Offset);
        Divide(P,X+Offset,Y+Offset,Offset);
    }
    else
    {
        if(Pivot) ResultB++;
        else      ResultW++;
    }
}
int main()
{
    int N=0;
    cin>>N;
    vector<vector<int>> P(N,vector<int>(N));
    for(int i=0;i<N;++i)
    {
        for(int j=0;j<N;++j)
        {
            cin>>P[i][j];
        }
    }
    Divide(P,0,0,N);
    cout<<ResultW<<"\n"<<ResultB;
}