#include "bits/stdc++.h"
using namespace std;

int N,M,K;
vector<vector<vector<int>>> Stickers;
vector<vector<int>> Map;
void Rotate(vector<vector<int>>& Sticker)
{
    int R=Sticker.size(), C=Sticker[0].size();
    vector<vector<int>> Temp(C,vector<int>(R,0));
    for(int i=0;i<R;++i)
    {
        for(int j=0;j<C;++j)
        {
            Temp[j][R-1-i]=Sticker[i][j];
        }
    }
    Sticker=move(Temp);
}
bool IsPossible(int Y, int X, vector<vector<int>>& Sticker)
{
    int R=Sticker.size(), C=Sticker[0].size();
    for(int i=0;i<R;++i)
    {
        for(int j=0;j<C;++j)
        {
            int Cy=Y+i, Cx=X+j;
            if(Map[Cy][Cx] && Sticker[i][j]) return false;
        }
    }
    return true;
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    
    cin>>N>>M>>K;
    Map.assign(N,vector<int>(M,0));
    Stickers.resize(K);
    for(auto& S : Stickers)
    {
        int R,C;
        cin>>R>>C;
        S.assign(R,vector<int>(C,0));
        for(auto& r : S)
        {
            for(auto& c : r)
            {
                cin>>c;
            }
        }
    }
    int Cnt=0;
    for(auto& S : Stickers)
    {
        bool bIsUsed=false;
        for(int D=0;D<4;++D)
        {
            int R=S.size(), C=S[0].size();
            for(int i=0;i<=N-R;++i)
            {
                for(int j=0;j<=M-C;++j)
                {
                    if(!IsPossible(i,j,S)) continue;
                    for(int r=0;r<R;++r)
                    {
                        for(int c=0;c<C;++c)
                        {
                            if(S[r][c])
                            {
                                Map[i+r][j+c]=1;
                                ++Cnt;
                            }
                        }
                    }
                    bIsUsed=true;
                    break;
                }
                if(bIsUsed) break;
            }
            if(bIsUsed) break;
            Rotate(S);
        }
    }
    cout<<Cnt;
}