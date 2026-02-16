#include "bits/stdc++.h"
using namespace std;

int dx[]={0,0,-1,1};
int dy[]={-1,1,0,0};
vector<string> A;
int Cnt=0;
bool IsConnected(vector<int>& Ans)
{
    bool Selected[5][5]={false}, Used[5][5]={false};
    int CntS=0;
    for(int Cur : Ans)
    {
        int Y=Cur/5, X=Cur%5;
        if(A[Y][X]=='S') ++CntS;
        Selected[Y][X]=true;
    }
    if(CntS < 4) return false;
    
    queue<pair<int,int>> Q;
    int Sy=Ans[0]/5, Sx=Ans[0]%5;
    Q.push({Sy,Sx});
    Used[Sy][Sx]=true;
    int ConnectedCnt=1;
    while(!Q.empty())
    {
        auto [Cy,Cx]=Q.front();
        Q.pop();
        for(int d=0;d<4;++d)
        {
            int Ny=Cy+dy[d], Nx=Cx+dx[d];
            if(Ny<0 || Ny>=5 || Nx<0 || Nx>=5 || Used[Ny][Nx] || !Selected[Ny][Nx]) continue;
            ++ConnectedCnt;
            Q.push({Ny,Nx});
            Used[Ny][Nx]=true;
        }
    }
    return ConnectedCnt==7;
}
void Comb(int Cur, vector<int>& Ans)
{
    if(Ans.size()==7)
    {
        if(IsConnected(Ans)) ++Cnt;
        return;
    }
    for(int i=Cur;i<25;++i)
    {
        Ans.push_back(i);
        Comb(i+1,Ans);
        Ans.pop_back();
    }
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    
    A.resize(5);
    for(auto& a : A) cin>>a;
    vector<int> Ans;
    Comb(0,Ans);
    cout<<Cnt;
}