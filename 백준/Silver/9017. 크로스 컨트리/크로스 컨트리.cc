#include "bits/stdc++.h"
using namespace std;

struct Team
{
    int Cnt;
    vector<int> Idx;
    Team()
    {
        Cnt=0;
    }
};

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    int T=0;
    cin>>T;
    
    while(T--)
    {
        int M;
        cin>>M;
        vector<int> TeamNum(M);
        map<int,Team> Info;
        map<int,int> Player;
        
        for(int i=0;i<M;++i)
        {
            cin>>TeamNum[i];
            Info[TeamNum[i]].Cnt++;
            Info[TeamNum[i]].Idx.push_back(i);
        }
        int Score=1;
        vector<int> TotalScore(Info.size()+1,0);
        for(int i=0;i<M;++i)
        {
            if(Info[TeamNum[i]].Cnt<6) continue;

            if (Player[TeamNum[i]]<4) TotalScore[TeamNum[i]]+=Score;
            Player[TeamNum[i]]++;
            Score++;
        }
        int MinScore=1e9, Winner=0;
        for (int i=1;i<TotalScore.size();++i)
        {
            if (!TotalScore[i]) continue;
            if (TotalScore[i]<MinScore || (TotalScore[i]==MinScore && Info[i].Idx[4]<Info[Winner].Idx[4]))
            {
                Winner=i;
                MinScore=TotalScore[i];
            }
        }
        cout<<Winner<<'\n';
    }
}