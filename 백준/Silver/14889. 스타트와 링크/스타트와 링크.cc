#include <vector>
#include <climits>
#include <iostream>
#include <algorithm>
using namespace std;
int Min=INT_MAX;
void DFS(int start,int count,int N, vector<vector<int>>& S, vector<bool>& Team)
{
    if(count==N/2)
    {
        int TrueSum=0,FalseSum=0;
        for(int i=0;i<N;i++)
        {
            for(int j=i+1;j<N;j++)
            {
                if(Team[i]&&Team[j])
                {
                    TrueSum+=S[i][j]+S[j][i];
                }
                else if(!Team[i]&&!Team[j])
                {
                    FalseSum+=S[i][j]+S[j][i];
                }
            }
        }
        Min=min(Min,abs(TrueSum-FalseSum));
        return;
    }
    for(int i=start;i<N;i++)
    {
        if(!Team[i])
        {
            Team[i]=true;
            DFS(i+1,count+1,N,S,Team);
            Team[i]=false;
        }
    }
}
int main()
{
    int N;
    cin>>N;
    vector<vector<int>> S(N,vector<int>(N,0));
    vector<bool> Team(N,false);
    for(int i=0;i<N;i++)
    {
        for(int j=0;j<N;j++)
        {
            cin>>S[i][j];
        }
    }
    DFS(0,0,N,S,Team);
    cout<<Min;
    return 0;
}