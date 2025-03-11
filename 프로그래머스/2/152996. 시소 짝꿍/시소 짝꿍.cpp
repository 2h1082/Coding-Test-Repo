#include <bits/stdc++.h>

using namespace std;

long long solution(vector<int> weights) {
    long long answer=0;
    unordered_map<int, int> weightsCount;
    
    for(int i:weights)
    {
        weightsCount[i]++;
    }
    
    sort(weights.begin(),weights.end());
    
    for(int i:weights)
    {
        if(weightsCount[i]==0) continue;
        if(weightsCount[i]>1) //중복 무게
        {
            answer+=(long long)(weightsCount[i]-1)*weightsCount[i]/2;
        }
        vector<pair<int,int>> ratio={{2,3},{3,4},{1,2}};
        for(auto [n1,n2]:ratio)
        {
            int target=n2*i/n1;
            if(weightsCount[target]&&(n2*i%n1)==0) 
            {
                answer+=(long long)weightsCount[target]*weightsCount[i];
            }
        }
        weightsCount[i]=0;
    }
    
    
    return answer;
}