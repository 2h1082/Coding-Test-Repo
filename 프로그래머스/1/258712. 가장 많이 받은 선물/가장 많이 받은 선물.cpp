#include <bits/stdc++.h>

using namespace std;

int solution(vector<string> friends, vector<string> gifts) {
    int answer = 0;
    unordered_map<string,unordered_map<string,int>> SendList;
    unordered_map<string,int> GiftDif;
    for(auto& gift:gifts)
    {
        stringstream str(gift);
        string from, to;
        str>>from>>to;
        
        SendList[from][to]++;
        GiftDif[from]++;
        GiftDif[to]--;
        
    }
    unordered_map<string,int> GiftCount;
    for(int i=0;i<friends.size()-1;i++)
    {
        for(int j=i+1;j<friends.size();j++)
        {
            if(SendList[friends[i]][friends[j]]>SendList[friends[j]][friends[i]]) GiftCount[friends[i]]++;
            else if(SendList[friends[i]][friends[j]]<SendList[friends[j]][friends[i]]) GiftCount[friends[j]]++;
            else
            {
                if(GiftDif[friends[i]]>GiftDif[friends[j]]) GiftCount[friends[i]]++;
                else if(GiftDif[friends[i]]<GiftDif[friends[j]]) GiftCount[friends[j]]++;
            }
        }
    }
    // Find maximum gift count
    for(auto& [friend_name, count] : GiftCount) {
        answer = max(answer, count);
    }
    return answer;
}