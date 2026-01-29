#include "bits/stdc++.h"
using namespace std;

int dy[]={-1,1,0,0};
int dx[]={0,0,-1,1};
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    
    int T;
    cin>>T;
    
    while(T--)
    {
        int H,W,Ans=0;
        cin>>H>>W;
        
        vector<string> Map(H);
        vector<vector<bool>> Used(H,vector<bool>(W,false));
        queue<pair<int,int>> Q;
        for(int i=0;i<H;++i)  cin>>Map[i];
        
        // 건물 밖에서 진입 가능한 곳들 시작지점으로 큐 삽입
        for(int i=0;i<H;++i)
        {
            for(int j=0;j<W;++j)
            {
                if((i==0 || i==H-1 || j==0 || j==W-1) && Map[i][j]!='*')
                {
                    Q.push({i,j});
                    Used[i][j]=true;
                }
            }
        }
        
        // 보유 중인 키 확인
        string K;
        cin>>K;
        vector<bool> Keys(26,false);
        if(K!="0") for(auto& k : K) Keys[k-'a']=true;
        vector<queue<pair<int,int>>> DoorQ(26);
        
        while(!Q.empty())
        {
            auto [Cy,Cx]=Q.front();
            Q.pop();
            char Cell=Map[Cy][Cx];
            if(Cell=='$')                   ++Ans;
            else if(Cell>='A' && Cell<='Z')
            {
                int KeyIdx=Cell-'A';
                if(!Keys[KeyIdx])
                {
                    DoorQ[KeyIdx].push({Cy,Cx});
                    continue;
                }
            }
            else if(Cell>='a' && Cell<='z') 
            {
                int KeyIdx=Cell-'a';
                Keys[KeyIdx]=true;
                while(!DoorQ[KeyIdx].empty())
                {
                    Q.push(DoorQ[KeyIdx].front());
                    DoorQ[KeyIdx].pop();
                }
            }
            for(int i=0;i<4;++i)
            {
                int Ny=Cy+dy[i], Nx=Cx+dx[i];
                if(Ny<0 || Ny>=H || Nx<0 || Nx>=W || Used[Ny][Nx] || Map[Ny][Nx]=='*') continue;
                Used[Ny][Nx]=true;
                Q.push({Ny,Nx});
            }
        }
        cout<<Ans<<'\n';
    }
}