#include <bits/stdc++.h>

using namespace std;

vector<int> solution(vector<vector<int>> users, vector<int> emoticons) {
    vector<int> answer(2,0);
    vector<vector<int>> price(7,vector<int>(2,0));
    int n=emoticons.size();
    function<void(int)> DFS=[&](int index)
    {
        if(index<n)
        {
            for(int i=10;i<=40;i+=10)
            {
                price[index][0]=(100-i)*emoticons[index]/100;
                price[index][1]=i;
                DFS(index+1);
            }
        }
        else
        {
            vector<int> cur(2,0);
            for(int i=0;i<users.size();i++)
            {
                int Total=0;
                for(int j=0;j<index;j++)
                {
                    if(price[j][1]>=users[i][0])
                    {
                        Total+=price[j][0];
                    }
                }
                if(Total>=users[i][1])
                {
                    cur[0]++;
                }
                else
                {
                    cur[1]+=Total;
                }
            }
            answer=max(answer,cur);
            return;
        }        
    };
    DFS(0);
    return answer;
}