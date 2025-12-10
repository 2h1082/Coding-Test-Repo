#include "bits/stdc++.h"
using namespace std;

// 비트 마스킹으로 7-Seg LED 칸 매핑 (0~9)
int Seg[10]={
    0b1110111,
    0b0010001,
    0b0111110,
    0b0111011,
    0b1011001,
    0b1101011,
    0b1101111,
    0b0110001,
    0b1111111,
    0b1111011
};

int N,K,P,X;
string ToStr(int Num)
{
    string S=to_string(Num);
    while(S.size() < K) S='0'+S;
    return S;
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    cin>>N>>K>>P>>X;
    
    vector<vector<int>> Diff(10,vector<int>(10,0));
    for(int i=0;i<10;++i)
    {
        for(int j=0;j<10;++j)
        {
            Diff[i][j]=__builtin_popcount(Seg[i]^Seg[j]);
        }
    }
    
    string Cur=ToStr(X);
    
    int Ans=0;
    for(int Floor=1;Floor<=N;++Floor)
    {
        if(Floor==X) continue;
        
        int CellCnt=0;
        string Nxt=ToStr(Floor);
        for(int i=0;i<K;++i)
        {
            CellCnt+=Diff[Nxt[i]-'0'][Cur[i]-'0'];
            if(CellCnt>P) break;
        }
        if(CellCnt<=P) Ans++;
    }
    cout<<Ans;
}