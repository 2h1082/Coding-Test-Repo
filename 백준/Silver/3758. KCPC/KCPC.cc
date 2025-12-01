#include "bits/stdc++.h"
using namespace std;

struct Team
{
    int ID, Total, LogCnt, Last;
    vector<int> Score;
    Team(int Id, int ProbCnt)
    {
        ID=Id;
        Score.assign(ProbCnt,0);
    }
    void Update(int Num, int S, int Idx)
    {
        if(Score[Num-1]<S)
        {
            Total+=S-Score[Num-1];
            Score[Num-1]=S;
        }
        Last=Idx;
        LogCnt++;
    }
        
    bool operator <(const Team& other) const
    {
        if(Total != other.Total)       return Total > other.Total;
        if(LogCnt != other.LogCnt)     return LogCnt < other.LogCnt;
        return Last < other.Last;
    }
};
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    int T;
    cin>>T;
    while(T--)
    {
        int N,K,ID,M;
        cin>>N>>K>>ID>>M;
        vector<Team> Ts;
        for(int i=0;i<N;++i) Ts.push_back(Team(i,K));
        
        for(int k=0;k<M;++k)
        {
            int i,j,s;
            cin>>i>>j>>s;
            
            Ts[i-1].Update(j,s,k);
        }
        sort(Ts.begin(),Ts.end());
        
        int Ans=1;
        for(auto& t : Ts)
        {
            if(ID-1==t.ID) break;
            Ans++;
        }
        cout<<Ans<<'\n';
    }
}