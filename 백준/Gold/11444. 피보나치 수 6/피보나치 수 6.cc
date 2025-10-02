#include <iostream>
#include <vector>

using namespace std;
long long D=1000000007;
vector<vector<long long>> Multiply(vector<vector<long long>> A, vector<vector<long long>> B)
{
    vector<vector<long long>> Result(A.size(),vector<long long>(B[0].size(),0));
    for(int i=0;i<Result.size();++i)
    {
        for(int j=0;j<Result[0].size();++j)
        {
            for(int k=0;k<A[0].size();++k)
            {
                Result[i][j]+=(A[i][k]*B[k][j])%D;
            }
        }
    }
    return Result;
}

vector<vector<long long>> MatrixPower(vector<vector<long long>>& Origin, long long N)
{
    if(N==1)
    {
        return Origin;
    }
    vector<vector<long long>> Res=MatrixPower(Origin,N/2);
    Res=Multiply(Res,Res);
    if(N%2)
    {
        return Multiply(Res,Origin);
    }
    else
    {
        return Res;
    }
}
int main()
{
    long long N=0;
    cin>>N;
    vector<vector<long long>> BaseMat={{1,1},{1,0}};
    vector<vector<long long>> Result={{0,0},{1,0}};
    BaseMat=MatrixPower(BaseMat,N);
    Result=Multiply(BaseMat,Result);
    cout<<Result[0][0];
}