#include <bits/stdc++.h>

using namespace std;
int N=0, W=0;
vector<pair<int,int>> Accident;
vector<vector<int>> DP, CarNum;
int Dist(int a, int b, int CarNum)
{
    pair<int,int> p1,p2;
    if(a==0&&CarNum==1)      p1={1,1};
    else if(a==0&&CarNum==2) p1={N,N};
    else p1=Accident[a];
    
    p2=Accident[b];
    
    return abs(p1.first-p2.first)+abs(p1.second-p2.second);
}

int Choice(int a, int b)
{
    int Nxt=max(a,b)+1;
    if(Nxt>W) return 0;
    if(DP[a][b]!=-1) return DP[a][b];
    
    int C1=Choice(Nxt,b)+Dist(a,Nxt,1);
    int C2=Choice(a,Nxt)+Dist(b,Nxt,2);
    
    if(C1<=C2)
    {
        CarNum[a][b]=1;
        return DP[a][b]=C1;
    }
    else
    {
        CarNum[a][b]=2;
        return DP[a][b]=C2;
    }
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    cin>>N>>W;
    
    Accident.assign(W+1,pair<int,int>());
    for(int i=1;i<=W;++i)
    {
        cin>>Accident[i].first>>Accident[i].second;
    }
    DP.assign(W+1,vector<int>(W+1,-1));
    CarNum.assign(W+1,vector<int>(W+1,0));
    cout<<Choice(0,0)<<"\n";
    
    int a=0,b=0;
    for(int i=1;i<=W;++i)
    {
        cout<<CarNum[a][b]<<"\n";
        if(CarNum[a][b]==1) a=max(a,b)+1;
        else                b=max(a,b)+1;
    }
}