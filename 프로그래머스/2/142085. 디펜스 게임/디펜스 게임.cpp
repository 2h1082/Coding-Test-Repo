#include <bits/stdc++.h>

using namespace std;

int solution(int n, int k, vector<int> enemy) {
    priority_queue<int, vector<int>, greater<int>> pq; // 최소 힙
    long long answer = 0; 
    
    for(int i = 0; i < enemy.size(); i++) {
        pq.push(enemy[i]);
        
        // 최소 힙을 이용해 가장 큰 값을 지닌 k개의 라운드 추적 -> 초과분 합산하여 처리
        if(pq.size() > k) {
            answer += pq.top();
            pq.pop();
        }
        
        // 현재 합계가 n을 초과하면 더 진행 불가
        if(answer > n) {
            return i;
        }
    }
    
    // 여기까지 왔으면 모든 웨이브를 버틴 것
    return enemy.size();
}