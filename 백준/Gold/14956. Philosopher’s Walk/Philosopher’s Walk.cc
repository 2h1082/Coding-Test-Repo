#include "bits/stdc++.h"
using namespace std;

int N,M;
pair<int,int> Solve(int Cnt, int Size)
{
    if(Size==2)
    {
        pair<int,int> Ans;
        // U를 아래로 뒤집은 모양을 기본형으로 상정
        if(Cnt==0) Ans={1,1};
        if(Cnt==1) Ans={1,2};
        if(Cnt==2) Ans={2,2};
        if(Cnt==3) Ans={2,1};
        return Ans;
    }
    int Half=Size/2, Walk=Half*Half;
    
    pair<int,int> Temp;
    // 모든 이동은 입구인 1구역 기준에서 이동 방향 판정
    // 1구역(왼쪽 아래) : 기본형을 ㄷ을 반대로 뒤집은 모양이 되도록 y=x축 대칭
    if(Cnt < Walk) 
    {
        Temp=Solve(Cnt,Half);
        swap(Temp.first,Temp.second);
    }
    // 2구역 (왼쪽 위) : y축 방향 이동 (기본형 그대로)
    else if(Cnt < 2*Walk)
    {
        Temp=Solve(Cnt-Walk,Half);
        Temp.second+=Half;
    }
    // 3구역 (오른쪽 위) : x, y 축 모두 이동 (기본형 그대로)
    else if(Cnt < 3*Walk)
    {
        Temp=Solve(Cnt-2*Walk,Half);
        Temp.first+=Half;
        Temp.second+=Half;
    }
    // 4구역 (오른쪽 아래) : 회전 및 대칭 이동 (ㄷ자 모양)
    else
    {
        Temp=Solve(Cnt-3*Walk,Half);
        int X=2*Half-Temp.second+1, Y=Half-Temp.first+1;
        Temp={X,Y};
    }
    return Temp;
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    
    cin>>N>>M;
    pair<int,int> Ans=Solve(M-1,N);
    cout<<Ans.first<<' '<<Ans.second;
}