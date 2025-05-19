#include <bits/stdc++.h>

using namespace std;

long long solution(int n, vector<int> times) {
    sort(times.begin(),times.end());
    
    long long l=0, r=(long long)times.back()*n;
    while(l<r)
    {
        long long mid=(l+r)/2;
        long long count=0;
        for(auto& time:times)
        {
            count+=mid/time;
        }
        
        if(count>=n)
        {
            r=mid;
        }
        else
        {
            l=mid+1;
        }
    }
    
    return l;
}