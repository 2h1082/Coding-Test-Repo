#include <bits/stdc++.h>

using namespace std;

vector<int> solution(vector<string> genres, vector<int> plays) {
    vector<int> answer;
    map<string,int> PlayCount;
    multimap<string,pair<int,int>> CountIdx;
    for(int i=0;i<genres.size();i++)
    {
        PlayCount[genres[i]]+=plays[i];
        CountIdx.insert({genres[i],{plays[i],i}});
    }
    vector<pair<string,int>> S(PlayCount.begin(),PlayCount.end());
    sort(S.begin(),S.end(),[&](auto& a,auto& b){
        return a.second>b.second;
    });
    for(auto it=S.begin();it!=S.end();it++)
    {
        int cnt=0;
        string g=it->first;
        vector<pair<int, int>> songList;
        auto range=CountIdx.equal_range(g);
        for(auto i=range.first;i!=range.second;i++)
        {
            songList.push_back(i->second);
        }
        sort(songList.begin(),songList.end(),[&](auto& a, auto& b){
            if(a.first==b.first) return a.second<b.second;
            return a.first>b.first;
        });
        for(int i=0;i<songList.size()&&i<2;i++)
        {
            answer.push_back(songList[i].second);
        }
    }
    return answer;
}