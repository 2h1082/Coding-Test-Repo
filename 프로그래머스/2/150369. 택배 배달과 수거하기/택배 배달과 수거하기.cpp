#include <bits/stdc++.h>

using namespace std;

long long solution(int cap, int n, vector<int> deliveries, vector<int> pickups) {
    long long answer = 0;
    int di=n-1, pi=n-1;
    while(di>=0||pi>=0)
    {
        while(di>=0&&deliveries[di]==0) di--;
        while(pi>=0&&pickups[pi]==0) pi--;
        if(di<0&&pi<0) break;
        
        int Dist=max(di,pi)+1;
        answer+=(long long)Dist*2;
        int count=cap;
        for(int i=di;i>=0&&count>0;--i)
        {
            int down=min(count,deliveries[i]);
            deliveries[i]-=down;
            count-=down;
        }
        count=cap;
        for(int i=pi;i>=0&&count>0;--i)
        {
            int up=min(count,pickups[i]);
            pickups[i]-=up;
            count-=up;
        }
    }
    return answer;
}