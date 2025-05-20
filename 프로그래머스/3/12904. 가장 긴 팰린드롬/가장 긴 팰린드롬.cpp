#include <bits/stdc++.h>

using namespace std;

int solution(string s)
{
    int answer=0;
    string t="^#";
    for(auto& c:s)
    {
        t+=c;
        t+='#';
    }
    t+='$';
    int n=t.length();
    vector<int> p(n,0);
    int c=0,r=0;
    for(int i=1;i<n-1;i++)
    {
        int m=2*c-i;
        if(i<r) p[i]=min(p[m],r-i);
        
        while(t[i+p[i]+1]==t[i-p[i]-1]) p[i]++;
        
        if(p[i]+i>r)
        {
            c=i;
            r=i+p[i];
        }
    }
    answer=*max_element(p.begin(),p.end());
    return answer;
}