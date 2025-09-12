#include <iostream>
#include <vector>

using namespace std;
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int N=0;
    cin>>N;
    vector<vector<int>> Matrix(N,vector<int>(N));
    for(int i=0;i<N;++i)
    {
        for(int j=0;j<N;++j)
        {
            cin>>Matrix[i][j];
        }
    }
    
    for(int k=0;k<N;++k)
    {
        for(int i=0;i<N;++i)
        {
            for(int j=0;j<N;++j)
            {
                Matrix[i][j]=Matrix[i][j]||(Matrix[i][k]&&Matrix[k][j]);
            }
        }
    }
    for(int i=0;i<N;++i)
    {
        for(int j=0;j<N;++j)
        {
            cout<<Matrix[i][j]<<" ";
        }
        cout<<"\n";
    }
}