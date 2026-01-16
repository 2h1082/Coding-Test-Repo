#include "bits/stdc++.h"
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    
    int N,L;
    cin>>N>>L;
    
    deque<pair<int,int>> Q;
    
    for(int i=0;i<N;++i)
    {
        int A;
        cin>>A;
        // 뒤에 추가될 수(A) 이상인 수들은 앞으로 최소값이 될 가능성이 없음
        // 삭제하여 후보군 오름차순 유지
        // - 가장 앞에 최솟값이 오도록하는 역할
        while(!Q.empty() && Q.back().first >= A) Q.pop_back();
        
        Q.push_back({A,i});
        // 가장 앞에 있는 최솟값 후보군의 인덱스가 범위 밖이면 삭제
        if(Q.front().second <= i-L) Q.pop_front(); 
        cout<<Q.front().first<<' ';
    }
}