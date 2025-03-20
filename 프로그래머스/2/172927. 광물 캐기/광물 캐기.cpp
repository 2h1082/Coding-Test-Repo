#include <bits/stdc++.h>

using namespace std;

int Min=INT_MAX;
void DFS(vector<int>& picks, vector<string>& minerals, int idx, int result, int pickIdx)
{
    int len=idx+5;
    for(;idx<len&&idx<minerals.size();idx++)
    {
        if(pickIdx==0)
        {
            result+=1;
        }
        else if(pickIdx==1)
        {
            if(minerals[idx]=="diamond")
            {
                result+=5;
            }
            else
            {
                result+=1;
            }
        }
        else if(pickIdx==2)
        {
            if(minerals[idx]=="diamond")
            {
                result+=25;
            }
            else if(minerals[idx]=="iron")
            {
                result+=5;
            }
            else
            {
                result+=1;
            }
        }
    }
    if(idx>=minerals.size()||picks[0]+picks[1]+picks[2]==0)
    {
        Min=min(Min,result);
        return;
    }
    if(picks[0]>0)
    {
        picks[0]--;
        DFS(picks,minerals,idx,result,0);
        picks[0]++;
    }
    if(picks[1]>0)
    {
        picks[1]--;
        DFS(picks,minerals,idx,result,1);
        picks[1]++;
    }
    if(picks[2]>0) 
    {
        picks[2]--;
        DFS(picks,minerals,idx,result,2);
        picks[2]++;
    }
}
int solution(vector<int> picks, vector<string> minerals) {
    if(picks[0]>0)
    {
        picks[0]--;
        DFS(picks,minerals,0,0,0);
        picks[0]++;
    }
    if(picks[1]>0)
    {
        picks[1]--;
        DFS(picks,minerals,0,0,1);
        picks[1]++;
    }
    if(picks[2]>0) 
    {
        picks[2]--;
        DFS(picks,minerals,0,0,2);
        picks[2]++;
    }
    return Min;
}