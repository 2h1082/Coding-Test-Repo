#include "bits/stdc++.h"
using namespace std;

int dy[]={-1,1,0,0};
int dx[]={0,0,-1,1};
struct UF
{
    vector<int> Parent, Size;
    UF(int N)
    {
        Parent.resize(N);
        iota(Parent.begin(),Parent.end(),0);
        Size.assign(N,1);
    }
    int Find(int A)
    {
        if(Parent[A]!=A) return Parent[A]=Find(Parent[A]);
        return A;
    }
    void Union(int A, int B)
    {
        int RootA=Find(A), RootB=Find(B);
        if(RootA==RootB) return;
        if(Size[RootA] < Size[RootB]) swap(RootA,RootB);
        Parent[RootB]=RootA;
        Size[RootA]+=Size[RootB];
    }
};
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    
    int R,C;
    cin>>R>>C;
    
    vector<string> Map(R);
    vector<pair<int,int>> Swan;
    queue<pair<int,int>> Q;
    vector<vector<bool>> Used(R,vector<bool>(C,false));
    UF Uf(R*C);
    for(int i=0;i<R;++i)
    {
        cin>>Map[i];
        for(int j=0;j<C;++j)
        {
            if(Map[i][j]=='X') continue;
            Q.push({i,j});
            Used[i][j]=true;
            if(Map[i][j]=='L') Swan.push_back({i,j});
            for(int d=0;d<4;++d)
            {
                int Ny=i+dy[d], Nx=j+dx[d];
                if(Ny<0 || Ny>=R || Nx<0 || Nx>=C || Used[Ny][Nx] || Map[Ny][Nx]=='X') continue;
                Uf.Union(i*C+j,Ny*C+Nx);
            }
        }
    }
    
    int Cnt=0, Swan1=Swan[0].first*C + Swan[0].second, Swan2=Swan[1].first*C + Swan[1].second;
    
    while(Uf.Find(Swan1) != Uf.Find(Swan2))
    {   
        queue<pair<int,int>> NxtQ;
        while(!Q.empty())
        {
            auto [Cy,Cx]=Q.front();
            Q.pop();
            for(int d=0;d<4;++d)
            {
                int Ny=Cy+dy[d], Nx=Cx+dx[d];
                if(Ny<0 || Ny>=R || Nx<0 || Nx>=C || Used[Ny][Nx] || Map[Ny][Nx]!='X') continue;
                Used[Ny][Nx]=true;
                Map[Ny][Nx]='.';
                NxtQ.push({Ny,Nx});
                for (int i=0;i<4;++i)
                {
                    int Nny=Ny+dy[i], Nnx=Nx+dx[i];
                    if(Nny<0 || Nny>=R || Nnx<0 || Nnx>=C || !Used[Nny][Nnx]) continue;
                    Uf.Union(Nny*C+Nnx,Ny*C+Nx);
                }
            }
        }
        Q=NxtQ;
        ++Cnt;
    }
    cout<<Cnt;
}
