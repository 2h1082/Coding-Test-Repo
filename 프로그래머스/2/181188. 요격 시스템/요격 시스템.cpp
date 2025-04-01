#include <bits/stdc++.h>

using namespace std;


int solution(vector<vector<int>> targets) {
    int answer = 0;
    sort(targets.begin(),targets.end(),[](vector<int>& a, vector<int>& b){
        return a[1]<b[1];
    });
    
    int e=-1;
    
    for(int i=0;i<targets.size();i++)
    {
        
        if(e<=targets[i][0])
        {
            answer++;
            e=targets[i][1];
        }        
    }
    return answer;
}