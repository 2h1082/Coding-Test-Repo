#include <string>
#include <queue>
#include <iostream>

using namespace std;

int solution(int bridge_length, int weight, vector<int> truck_weights) {
    int answer = 0;
    queue<pair<int, int>> Time;
    int OnWeight=0;
    
    for(int i=0;i<truck_weights.size();i++)
    {
        answer++;
        if(answer-Time.front().second>=bridge_length) 
        {
            OnWeight-=Time.front().first;
            Time.pop();
        }
        while(OnWeight+truck_weights[i]>weight || Time.size()==bridge_length)
        {
            cout<<"time:"<<answer<<" "<<"truck:"<<Time.front().second<<endl;
            answer+=bridge_length-(answer-Time.front().second);
            OnWeight-=Time.front().first;
            Time.pop();   
        }
        if(OnWeight+truck_weights[i]<=weight && Time.size()<bridge_length)
        {
            OnWeight+=truck_weights[i];
            Time.push({truck_weights[i],answer});
        }
    }
    if(!Time.empty()) answer+=bridge_length;
    
    return answer;
}