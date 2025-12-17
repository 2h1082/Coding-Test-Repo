#include "bits/stdc++.h"
using namespace std;

vector<int> Cnt={6,2,5,5,4,5,6,3,7,6};

bool IsBetter(string& A, string& B)
{
    if(B.empty()) return true;
    if(A.length() != B.length()) return A.length() < B.length();
    return A < B; // 길이가 같으면 사전순 비교
    
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    int T;
    cin>>T;
    
    vector<string> Dp(101,"");
    Dp[2]="1";
    Dp[3]="7";
    Dp[4]="4";
    Dp[5]="2";
    Dp[6]="6";
    Dp[7]="8";
    for(int i=8;i<=100;++i)
    {
        for(int Cur=0;Cur<=9;++Cur)
        {
            int Cost=Cnt[Cur];
            if(i-Cost<0)                 continue; // 불가능한 경우의 수 (만들 수 있는 수가 없음)
            if(Dp[i-Cost].empty())       continue; // 불가능한 경우의 수
            if(i-Cost==0 && Cur==0)      continue; // 맨 앞의 수로 0 불가

            string Cand=Dp[i-Cost]+char(Cur+'0');

            if(IsBetter(Cand,Dp[i])) Dp[i]=Cand;
        }
    }
    
    while(T--)
    {
        int N;
        cin>>N;
        
        string Max;
        int MaxN=N;
        if(N%2) 
        {
            Max+='7';
            MaxN-=3;
        }
        for(int i=MaxN;i>0;i-=2) Max+='1';
        
        
        
        cout<<Dp[N]<<' '<<Max<<'\n';
    }
}