#include <iostream>
#include <vector>
#include <climits>

using namespace std;
int main()
{
    int N=0, M=0;
    cin>>N>>M;
    vector<vector<int>> Bus(N,vector<int>(N,INT_MAX));
    for(int i=0;i<N;++i)
    {
        Bus[i][i]=0;
    }
    for(int i=0;i<M;++i)
    {
        int From,To,Cost;
        cin>>From>>To>>Cost;
        Bus[From-1][To-1]=min(Bus[From-1][To-1],Cost);
    }
    for(int k=N-1;k>=0;--k)
    {
        for(int i=0;i<N;++i)
        {
            for(int j=0;j<N;++j)
            {
                if(Bus[i][k]!=INT_MAX&&Bus[k][j]!=INT_MAX)
                {
                    Bus[i][j]= min(Bus[i][j],Bus[i][k]+Bus[k][j]);
                }
            }
        }
    }
    
    for(int i=0;i<N;++i)
    {
        for(int j=0;j<N;++j)
        {
            if (Bus[i][j]==INT_MAX)
            {
                cout<<"0 ";
            }
            else
            {
                cout<<Bus[i][j]<<" ";
            }
        }
        cout<<"\n";
    }
}