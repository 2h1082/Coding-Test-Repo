#include <bits/stdc++.h>

using namespace std;

vector<vector<int>> Visited;
int IsCycle(int r, int c, vector<string>& Map)
{
    if(Visited[r][c]==2) return 0;
    
    if(Visited[r][c]==1)
    {
        Visited[r][c]=2;
        return 1;
    }
    Visited[r][c]=1;
    
    int Nr=r, Nc=c;
    if(Map[r][c]=='L') Nc--;
    else if(Map[r][c]=='R') Nc++;
    else if(Map[r][c]=='D') Nr++;
    else if(Map[r][c]=='U') Nr--;
    
    int bIsCycle=IsCycle(Nr,Nc,Map);
    
    Visited[r][c]=2;
    return bIsCycle;
}
int main()
{
    int N,M;
    cin>>N>>M;
    Visited.assign(N,vector<int>(M,0));
    
    vector<string> Map(N);
    for(auto& S : Map)
    {
        cin>>S;
    }
    int Cnt=0;
    for(int r=0;r<N;++r)
    {
        for(int c=0;c<M;++c)
        {
            if(!Visited[r][c])
            {
                Cnt+=IsCycle(r,c,Map);
            }
        }
    }
    cout<<Cnt;
}