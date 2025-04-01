#include <bits/stdc++.h>

using namespace std;

int solution(vector<vector<int>> targets) {
    int answer = 0;
    sort(targets.begin(),targets.end());
    int s=targets[0][0];
    int e=targets[0][1];
    
    for(int i=1;i<targets.size();i++)
    {
        if(e<=targets[i][0])
        {
            answer++;
            s=targets[i][0];
            e=targets[i][1];
        }
        else
        {
           s=targets[i][0];
           e= e>targets[i][1]?targets[i][1]:e; 
        }
        
    }
    return answer+1;
}