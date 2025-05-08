#include <bits/stdc++.h>

using namespace std;

int solution(vector<vector<int>> scores) {
    int answer = 0;
    int n=scores.size();
    vector<vector<int>> TempV;
    int WanhoSum=scores[0][0]+scores[0][1];
    vector<bool> Incentive(n,true);
    
    for(int i=0;i<n;i++)
    {
        TempV.push_back({scores[i][0],scores[i][1],i});
    }
    
    sort(TempV.begin(),TempV.end(),[](auto &a, auto &b){
        if(a[0]!=b[0]) return a[0]>b[0]; 
        return a[1]>b[1];
    });
    
    int MaxFirstIdx=INT_MIN;
    int TempMax=MaxFirstIdx;
    //인센티브를 받지 못하는 사람 체크
    for(int i=0;i<n;i++)
    {
        int j=i;
        while(j<n&&TempV[j][0]==TempV[i][0]) ++j;
        for(int k=i;k<j;k++)
        {
            if(TempV[k][1]<MaxFirstIdx) Incentive[TempV[k][2]]=false;
            TempMax=max(TempMax,TempV[k][1]);
        }
        MaxFirstIdx=TempMax;
        i=j-1;
    }
    //완호가 인센티브 못 받는지 체크
    if(!Incentive[0]) return -1;
    
    //등수 체크
    vector<int> Sums;
    for(int i=0;i<n;i++)
    {
        if(Incentive[i])
        {
            Sums.push_back(scores[i][0]+scores[i][1]);
        }
    }
    sort(Sums.begin(),Sums.end(),greater<int>());
    for(int i=0;i<Sums.size();i++)
    {
        if(Sums[i]>WanhoSum) answer++;
        else break;
    }
    return answer+1;
}