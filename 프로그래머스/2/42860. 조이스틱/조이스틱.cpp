#include <bits/stdc++.h>

using namespace std;

int solution(string name) {
    int answer = 0;
    int n=name.length();
    string temp(n,'A');
    if(temp==name) return 0;
    int Min=n-1;
    for(int i=0;i<n;i++)
    {
        if(temp[i]!=name[i])
        {
            int up=name[i]-'A';
            int down=26-up;
            answer+=min(up,down);
            int next=i+1;
            while(next<n&&name[next]=='A') next++;
            int left=i;
            int right=n-next;
            Min=min(Min,left+right+min(left,right));
        }
    }
    return answer+Min;
}