#include "bits/stdc++.h"
using namespace std;
vector<map<int,int>> Adj;
vector<int> Ans;
int N=0;
void DFS(int Cur)
{
    while(!Adj[Cur].empty())
    {
        auto it = Adj[Cur].begin();
        int Nxt=it->first;
        
        --it->second;
        if(it->second==0) Adj[Cur].erase(it);
        
        auto Rev_it = Adj[Nxt].find(Cur);
        --Rev_it->second;
        if(Rev_it->second==0) Adj[Nxt].erase(Rev_it);
        
        DFS(Nxt);
    }
    Ans.push_back(Cur);
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    
    cin>>N;
    Adj.assign(N,map<int,int>());
    vector<int> Deg(N,0);
    for(int i=0;i<N;++i)
    {
        for(int j=0;j<N;++j)
        {
            int c;
            cin>>c;
            
            // i <= j 일 때만 처리 (대각선 포함)
            if(i <= j) 
            {
                if(c > 0)
                {
                    // Deg[i]와 Deg[j]를 c만큼 증가
                    Deg[i] += c;
                    Deg[j] += c;

                    // i != j 인 경우에만 Adj에 저장 (자기 루프는 DFS 탐색에서 제외)
                    if (i != j) {
                        Adj[i][j] += c; // i -> j 간선 c개 저장
                        Adj[j][i] += c; // j -> i 간선 c개 저장
                    }
                    // i == j (자기 루프)인 경우는 Deg에만 포함하고, Adj에 저장하지 않아도 DFS 작동에 문제 없음.
                }
            }
        }
    }
    
    for(int i=0;i<N;++i)
    {
        if(Deg[i]%2!=0)
        {
            cout<<-1;
            return 0;
        }
    }
    
    int Start=-1;
    for(int i=0;i<N;++i)
    {
        if(Deg[i]>0)
        {
            Start=i;
            break;
        }
    }
    if(Start==-1) 
    {
        cout<<-1;
        return 0;
    }
    DFS(Start);
    
    int UsedCnt=Ans.size();
    int EdgeCnt=accumulate(Deg.begin(),Deg.end(),0)/2;
    
    if(UsedCnt!=EdgeCnt+1)
    {
        cout<<-1;
        return 0;
    }
    
    for(int v : Ans)
    {
        cout<<v+1<<' ';
    }
}