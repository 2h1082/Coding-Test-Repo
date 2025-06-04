#include <vector>
#include <unordered_map>
#include <algorithm>
using namespace std;

int solution(vector<int> a) {
    int n = a.size();
    if (n < 2) return 0;

    // 1) 빈도 세기
    unordered_map<int, int> freq;
    freq.reserve(n);
    for (int v : a) {
        freq[v]++;
    }

    // 2) (숫자, 빈도) 쌍을 벡터로 옮기고 빈도 내림차순 정렬
    vector<pair<int,int>> items;
    items.reserve(freq.size());
    for (auto &kv : freq) {
        items.emplace_back(kv.first, kv.second);
    }
    sort(items.begin(), items.end(), [](auto &L, auto &R) {
        return L.second > R.second; 
    });

    int bestLen = 0;   // 지금까지 찾은 최대 스타 수열 길이

    // 3) 빈도가 큰 숫자부터 차례로 시도
    for (auto &p : items) {
        int x = p.first;
        int countX = p.second;

        // 이미 이 숫자로 최대 만들 수 있는 길이 <= bestLen이면 더 볼 필요 없음
        if (countX * 2 <= bestLen) {
            break;  // 뒤쪽은 빈도가 더 낮으므로 전부 건너뜀
        }

        // 4) 실제로 쌍을 만들 수 있는 개수를 O(N)으로 계산
        int pairs = 0;
        int i = 0;
        while (i < n - 1) {
            // a[i], a[i+1]를 하나의 쌍으로 잡을 수 있으면
            if ((a[i] == x || a[i+1] == x) && (a[i] != a[i+1])) {
                pairs++;
                i += 2;  // 다음 인덱스로 건너뛰기
            } else {
                i += 1;  // 그냥 다음 인덱스로 이동
            }
        }

        int lengthWithX = pairs * 2;  // “쌍 개수 × 2”가 최종 길이
        bestLen = max(bestLen, lengthWithX);
    }

    return bestLen;
}
