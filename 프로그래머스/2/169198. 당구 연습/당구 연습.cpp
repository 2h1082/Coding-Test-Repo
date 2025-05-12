#include <string>
#include <vector>
#include <limits>

using namespace std;

vector<int> solution(int m, int n, int startX, int startY, vector<vector<int>> balls) {
    vector<int> answer;
    answer.reserve(balls.size());
    
    // 네 개의 '한 번만 반사' 이미지: 왼쪽, 오른쪽, 아래, 위
    for (auto &b : balls) {
        int x2 = b[0], y2 = b[1];
        long long best = numeric_limits<long long>::max();
        
        // (tx,ty)는 반사된 목표 공의 가상 위치
        vector<pair<int,int>> targets = {
            { -x2,      y2     },  // 왼쪽 벽에 반사
            { 2*m - x2, y2     },  // 오른쪽 벽에 반사
            {  x2,     -y2     },  // 아래 벽에 반사
            {  x2,      2*n-y2 }   // 위쪽 벽에 반사
        };
        
        for (auto &[tx,ty] : targets) {
            long long dx = tx - startX;
            long long dy = ty - startY;
            
            // “벽에 한 번” 반사 경로만: 직접(0회) 혹은 다중 반사 경로는 targets에 없음
            
            // — 잘못된 경로 필터링 —
            // (1) 수평 반사(왼쪽/오른쪽)인데, y가 같다 → 실제 공(x2,y2)이
            //     startX↔tx 사이에 있으면, 반사 전 공에 먼저 맞음 ⇒ skip
            if (ty == startY) {
                long long lo = min<long long>(startX, tx);
                long long hi = max<long long>(startX, tx);
                if (lo < x2 && x2 < hi) continue;
            }
            // (2) 수직 반사(위/아래)인데, x가 같다 → 실제 공이 
            //     startY↔ty 사이에 있으면, 반사 전 공에 먼저 맞음 ⇒ skip
            if (tx == startX) {
                long long lo = min<long long>(startY, ty);
                long long hi = max<long long>(startY, ty);
                if (lo < y2 && y2 < hi) continue;
            }
            
            long long dist2 = dx*dx + dy*dy;
            if (dist2 < best) best = dist2;
        }
        
        answer.push_back((int)best);
    }
    
    return answer;
}
