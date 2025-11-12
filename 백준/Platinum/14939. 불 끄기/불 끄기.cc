#include <bits/stdc++.h>
using namespace std;
using ll=long long;

vector<string> L;
vector<int> LightOn;
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    
    L.assign(10,"");
    LightOn.assign(10,0);
    for(int i=0;i<10;++i) 
    {
        cin>>L[i];
        for(int j=0;j<10;++j)
        {
            if(L[i][j]=='O') LightOn[i]|=(1<<j);
        }
    }
    int Ans=1e9;
    //
    for(int Mask=0;Mask<(1<<10);++Mask)
    {
        vector<int> Cur=LightOn;
        int Cnt=0;
        // 1행
        for(int i=0;i<10;++i)
        {
            if(Mask&(1<<i))
            {
                Cnt++;
                Cur[0]^=(1<<i);
                if(i>0) Cur[0]^=(1<<(i-1));
                if(i<9) Cur[0]^=(1<<(i+1));
                Cur[1]^=(1<<i);
            }
        }
        // 2~10행
        for(int i=1;i<10;++i)
        {
            for(int j=0;j<10;++j)
            {
                if(Cur[i-1]&(1<<j))
                {
                    Cnt++;
                    Cur[i-1]^=(1<<j);
                    if(j>0) Cur[i]^=(1<<(j-1));
                    if(j<9) Cur[i]^=(1<<(j+1));
                    Cur[i]^=(1<<j);
                    if(i<9) Cur[i+1]^=(1<<j);
                }
            }
        }
        if(Cur[9]==0) Ans=min(Ans,Cnt);
    }
    cout<< (Ans==1e9 ? -1 : Ans)<<'\n';
}