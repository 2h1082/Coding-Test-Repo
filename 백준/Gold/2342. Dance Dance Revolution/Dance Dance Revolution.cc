#include <bits/stdc++.h>

using namespace std;
int INF=1e9;
int GetCost(int F, int T)
{
    if(F==T) return 1;
    if(F==0) return 2;
    int Diff=abs(F-T);
    if(Diff==2) return 4;
    if(Diff==1 || Diff==3) return 3;
    return INF;
}
int main()
{
    int Num=0;
    vector<int> Com;
    
    while(cin>>Num&&Num)
    {
        Com.push_back(Num);
    }
    if(Com.empty())
    {
        cout<<0;
        return 0;
    }
    vector<vector<vector<int>>> DP(Com.size(),vector<vector<int>>(5,vector<int>(5,INF)));
    DP[0][Com[0]][0]=DP[0][0][Com[0]]=2;
    for(int i=1;i<Com.size();++i)
    {
        int Target=Com[i];
        for(int l=0;l<5;++l)
        {
            for(int r=0;r<5;++r)
            {
                if(DP[i-1][l][r]==INF) continue;
                
                if(r!=Target)
                {
                    int NewCost=DP[i-1][l][r]+GetCost(l,Target);
                    DP[i][Target][r]=min(NewCost,DP[i][Target][r]);
                }
                if(l!=Target)
                {
                    int NewCost=DP[i-1][l][r]+GetCost(r,Target);
                    DP[i][l][Target]=min(NewCost,DP[i][l][Target]);
                }
            }
        }
    }
    int Res=INF;
    
    if(!Com.empty())
    {
        int N=Com.size()-1;
        for(int l=0;l<5;++l)
        {
            for(int r=0;r<5;++r)
            {
                Res=min(Res,DP[N][l][r]);
            }
        }
    }
    cout<<Res;
}