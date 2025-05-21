#include <bits/stdc++.h>

using namespace std;

int solution(vector<int> a) {
    int answer = 0;
    int n=a.size();
    vector<int> l(n,a[0]), r(n,a[n-1]);
    
    for(int i=1;i<n;i++)    l[i]=min(l[i-1],a[i]);
    for(int i=n-2;i>=0;i--) r[i]=min(r[i+1],a[i]);
    
    for(int i=0;i<n;i++)
    {
        bool left=(i==0)||a[i]<=l[i-1];
        bool right=(i==n-1)||a[i]<=r[i+1];
        if(left||right)
        {
            ++answer;
        }
    }
    return answer;
}