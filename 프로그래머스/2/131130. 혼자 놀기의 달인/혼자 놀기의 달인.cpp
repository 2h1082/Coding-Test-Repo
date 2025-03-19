#include <string>
#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

int solution(vector<int> cards) {
    int answer = 0;
    vector<bool> Visited(cards.size(),false);
    vector<int> Count;
    for(int i=0;i<cards.size();i++)
    {
        if(!Visited[i])
        {
            int count=0;
            int Idx=i;
            while(!Visited[Idx])
            {
                Visited[Idx]=true;
                count++;
                Idx=cards[Idx]-1;
            }
            Count.push_back(count);
        }
    }
    if(Count.size()<2) return 0;
    sort(Count.begin(),Count.end(),greater<int>());
    answer=Count[0]*Count[1];
    return answer;
}