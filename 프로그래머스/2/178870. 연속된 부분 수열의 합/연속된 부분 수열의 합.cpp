#include <bits/stdc++.h>

using namespace std;

vector<int> solution(vector<int> sequence, int k) {
    vector<int> answer;
    int start=0, end=0, sum=sequence[0], len=sequence.size();
    int MinLength=INT_MAX;
    pair<int,int> proper={-1,-1};
    
    while(end<len)
    {
        if(sum<k)
        {
            ++end;
            if(end<len) sum+=sequence[end];
        }
        else
        {
            if(sum==k)
            {
                int length=end-start+1;
                if(length<MinLength)
                {
                    MinLength=length;
                    proper={start,end};
                }
            }
            sum-=sequence[start];
            ++start;
        }
    }
    return {proper.first,proper.second};
}