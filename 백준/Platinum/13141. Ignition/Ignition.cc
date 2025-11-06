#include <bits/stdc++.h>

using namespace std;

int main()
{
    int N,M;
    cin>>N>>M;
    
    vector<vector<int>> Graph(N+1,vector<int>(N+1,1e9));
    vector<tuple<int,int,double>> Edges;
    for(int i=0;i<=N;++i) Graph[i][i]=0;
    while(M--)
    {
        int S,E,L;
        cin>>S>>E>>L;
        Graph[S][E]=Graph[E][S]=min(L,Graph[S][E]);
        Edges.push_back({S,E,L});
    }
    
    for(int k=1;k<=N;++k)
    {
        for(int i=1;i<=N;++i)
        {
            for(int j=1;j<=N;++j)
            {
                Graph[i][j]=min(Graph[i][j],Graph[i][k]+Graph[k][j]);
            }
        }
    }
    double Ans=1e9;
    for(int s=1;s<=N;++s)
    {
        double T=0;
        for(auto& [u,v,w]:Edges)
        {
            double t1=Graph[s][u];
            double t2=Graph[s][v];
            double Burn=max(t1,t2)+(w-fabs(t1-t2))/2.0;
            T=max(T,Burn);
        }
        Ans=min(Ans,T);
    }
    cout<<fixed<<setprecision(1)<<Ans;
}