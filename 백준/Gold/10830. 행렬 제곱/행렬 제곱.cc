#include <iostream>
#include <vector>

using namespace std;
int D=1000, N=0;

vector<vector<long long>> Multiply(vector<vector<long long>> Matrix1, vector<vector<long long>> Matrix2)
{
    vector<vector<long long>> Result(N,vector<long long>(N,0));
    for(int i=0;i<N;++i)
    {
        for(int j=0;j<N;++j)
        {
            for(int k=0;k<N;++k)
            {
                Result[i][j]+=Matrix1[i][k]*Matrix2[k][j]%D;
                Result[i][j]%=D;
            }
        }
    }
    return Result;
}
vector<vector<long long>> MatrixPower(vector<vector<long long>> Matrix, long long B)
{
    if(B==1)
    {
        return Matrix;
    }
    vector<vector<long long>> Nums=MatrixPower(Matrix,B/2);
    vector<vector<long long>> Result=Multiply(Nums,Nums);
    if(B%2)
    {
        return Multiply(Result,Matrix);
    }
    else
    {
        return Result;
    }
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    long long B=0;
    cin>>N>>B;
    vector<vector<long long>> Input(N,vector<long long>(N,0));
    
    if(B==0)
    {
        for (int i=0;i<N;++i)
        {
            Input[i][i]=1;
        }
        B=1;
    }
    else{
        for(int i=0;i<N;++i)
        {
            for(int j=0;j<N;++j)
            {
                cin>>Input[i][j];
                Input[i][j]%=D;
            }
        }
    }
    vector<vector<long long>> Result=MatrixPower(Input,B);
    for(int i=0;i<N;++i)
    {
        for(int j=0;j<N;++j)
        {
            cout<<Result[i][j]<<" ";
        }
        cout<<"\n";
    }
}