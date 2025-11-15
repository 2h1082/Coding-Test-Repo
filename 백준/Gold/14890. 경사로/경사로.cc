#include <bits/stdc++.h>
using namespace std;

int N=0,L=0;
bool CheckPath(vector<int>& Map)
{
    int PrevCnt=1, PrevLevel=Map[0];
    for(int j=1;j<N;++j)
    {
        if(PrevLevel==Map[j]) 
        {
            ++PrevCnt;
            continue;
        }
        if(abs(PrevLevel-Map[j])>1) return false;
        
        if(PrevLevel-Map[j]==1) // 낮아지는 구간
        {
            PrevCnt=1;
            
            for(int k=0;k<L;++k)
            {
                if(j+k>=N || Map[j+k]!=Map[j]) return false;
            }
            j+=L-1;
            PrevCnt=0;
            PrevLevel=Map[j];
            continue;
        }
        if(PrevLevel-Map[j]==-1) // 높아지는 구간
        {
            if(PrevCnt<L) return false;

            PrevCnt=1;
            PrevLevel=Map[j];
            continue;
        }
    }  
    return true;
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    cin>>N>>L;
    
    vector<vector<int>> Map(N,vector<int>(N,0));
    for(auto& r : Map)
    {
        for(auto& c : r)
        {
            cin>>c;
        }
    }
    int Cnt=0;
    for(int i=0;i<N;++i) 
        if(CheckPath(Map[i])) ++Cnt;
    
    for(int i=0;i<N;++i)
    {
        vector<int> Col(N,0);
        for(int j=0;j<N;++j)
        {
            Col[j]=Map[j][i];
        }
        if(CheckPath(Col)) ++Cnt;
    }
    
    cout<<Cnt;
}