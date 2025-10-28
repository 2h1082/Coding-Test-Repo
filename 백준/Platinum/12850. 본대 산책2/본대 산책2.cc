#include <bits/stdc++.h>

using namespace std;
using ll=long long;
int D=0, Mod=1000000007;
vector<vector<ll>> Origin;
vector<vector<ll>> MultiplyMat(vector<vector<ll>> Mat1, vector<vector<ll>> Mat2)
{
    vector<vector<ll>> Res(8,vector<ll>(8,0));
    for(int i=0;i<8;++i)
    {
        for(int j=0;j<8;++j)
        {
            for(int k=0;k<8;++k) 
            {
                Res[i][j]+=(Mat1[i][k]*Mat2[k][j]);
                Res[i][j]%=Mod;
            }
        }
    }
    return Res;
}
vector<vector<ll>> CountPath(vector<vector<ll>> Mat, int D)
{
    if(D==1)
    {
        return Mat;
    }
    vector<vector<ll>> Res=CountPath(Mat,D/2);
    Res=MultiplyMat(Res,Res);
    if(D%2)
    {
        return MultiplyMat(Res,Origin);
    }
    else
    {
        return Res;
    }
}
int main()
{
    cin>>D;
    Origin.assign(8,vector<ll>(8,0));
    Origin[0][1]=Origin[0][2]=1;
    Origin[1][0]=Origin[1][2]=Origin[1][3]=1;
    Origin[2][0]=Origin[2][1]=Origin[2][3]=Origin[2][5]=1;
    Origin[3][1]=Origin[3][2]=Origin[3][4]=Origin[3][5]=1;
    Origin[4][3]=Origin[4][5]=Origin[4][6]=1;
    Origin[5][3]=Origin[5][4]=Origin[5][2]=Origin[5][7]=1;
    Origin[6][4]=Origin[6][7]=1;
    Origin[7][5]=Origin[7][6]=1;
    vector<vector<ll>> Res=CountPath(Origin,D);
    cout<<Res[0][0];
}
/*
0 : 정보과학관
1 : 전산관
2 : 미래관
3 : 신양관
4 : 진리관
5 : 한경직기념관
6 : 학생회관
7 : 형남공학관
*/