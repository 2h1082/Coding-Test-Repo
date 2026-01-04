#include "bits/stdc++.h"
using namespace std;

int solution(int N, int Number) 
{
    vector<set<int>> Dp(9);
    
    // 단순 이어붙여서 만드는 수 삽입
    int Prev=0;
    for(int i=1;i<9;++i)
    {
        Prev=Prev*10 + N;
        Dp[i].insert(Prev);
    }

    // Dp 점화식 갱신
    // - 낮은 횟수부터 차례로 생성 가능한 수 갱신
    for(int i=1;i<9;++i)
    {
        for(int j=1;j<i;++j)
        {
            int k=i-j;
            for(const int& a : Dp[j])
            {
                for(const int& b : Dp[k])
                {
                    Dp[i].insert(a+b);
                    Dp[i].insert(a-b);
                    Dp[i].insert(a*b);
                    if(b) Dp[i].insert(a/b);
                }
            }
        }
        if(Dp[i].count(Number)) return i;
    }
    return -1;
}