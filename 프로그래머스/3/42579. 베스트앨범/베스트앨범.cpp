#include <bits/stdc++.h>
using namespace std;

vector<int> solution(vector<string> Genres, vector<int> Plays) 
{
    int N=Plays.size();
    map<string, int> TypeCnt;
    map<string, vector<pair<int,int>>> SongInfo;
    for(int i=0;i<N;++i)
    {
        TypeCnt[Genres[i]]+=Plays[i];
        SongInfo[Genres[i]].push_back({Plays[i],i});
    }
    
    vector<pair<string,int>> SortedType(TypeCnt.begin(),TypeCnt.end());
    sort(SortedType.begin(),SortedType.end(),[](const auto& P1, const auto& P2){
        return P1.second > P2.second;
    });
    
    vector<int> Ans;
    for(auto& [Type, TotalCnt]:SortedType)
    {
        sort(SongInfo[Type].begin(),SongInfo[Type].end(),[](const auto& P1, const auto& P2){
            if(P1.first==P2.first) return P1.second < P2.second;
            return P1.first > P2.first;
        });
        int Cnt=0;
        for(auto& [PlayCnt, Idx]:SongInfo[Type])
        {
            if(Cnt>=2) break;
            Ans.push_back(Idx);
            Cnt++;
        }
    }
    return Ans;
}