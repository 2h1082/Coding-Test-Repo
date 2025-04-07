#include <bits/stdc++.h>

using namespace std;

vector<int> solution(int n, vector<int> info) {
    vector<int> answer={-1};
    vector<int> best(11,0);
    int MaxDiff=0;
    function <void(int,int,vector<int>)> DFS=[&](int num,int idx,vector<int> lion)
    {
        if(num==n)
        {
            int sum=0;
            int Peach=0;
            for(int i=0;i<11;i++)
            {
                if(info[i]<lion[i]) sum+=10-i;
                else if(info[i]>0) Peach+=10-i;
            }
            if(sum>Peach)
            {
                int diff = sum - Peach;
                if (diff > MaxDiff || (diff == MaxDiff && lexicographical_compare(best.rbegin(), best.rend(), lion.rbegin(), lion.rend()))) {
                    MaxDiff = diff;
                    best = lion;
                }
            }
            return;
        }
        for(int i=idx;i<11;i++)
        {
            if(lion[i]>info[i]) continue;
            lion[i]++;
            DFS(num+1,i,lion);
            lion[i]--;
        }
    };
    vector<int> lion(11,0);
    DFS(0,0,lion);
    return MaxDiff>0?best:answer;
}