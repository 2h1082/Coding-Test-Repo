#include "bits/stdc++.h"
using namespace std;

int solution(vector<int> Citations) {
    int Ans = 0, H=0, N=Citations.size();
    
    // 거꾸로 내림차순 정렬
    // 큰값부터 확인하는 것이 유리
    sort(Citations.rbegin(),Citations.rend());
    for(int i=0;i<N;++i)
    {
        ++H;
        // 현재 인덱스의 인용 횟수가 H(현재 인용 횟수 이상의 논문 개수)보다 작으면 조건 만족하는 최댓값이니 바로 종료
        if(Citations[i] < H)
        {
            Ans=H-1;
            break;
        }
        if(H==N && Citations[i] > H) Ans=H;
    }
    
    return Ans;
}