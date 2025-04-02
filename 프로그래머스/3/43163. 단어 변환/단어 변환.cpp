#include <bits/stdc++.h>

using namespace std;
bool CanConvert(string& s1, string& s2)
{
    int dif=0;
    for(int i=0;i<s1.length();i++)
    {
        if(s1[i]!=s2[i]) dif++;
        if(dif>1) return false;
    }
    return dif==1;
}
int solution(string begin, string target, vector<string> words) {
    vector<bool> visited(words.size(),false);
    queue<pair<string,int>> q;
    auto it=find(words.begin(),words.end(),target);
    if(it==words.end()) return 0;
    q.push({begin,0});
    while(!q.empty())
    {
        string cur=q.front().first;
        int count=q.front().second;
        q.pop();
        if(target==cur)
        {
            return count;
        }
        for(int i=0;i<words.size();i++)
        {
            if(!visited[i]&&CanConvert(words[i],cur))
            {
                visited[i]=true;
                q.push({words[i],count+1});
            }
        }
    }
    
    return 0;
}