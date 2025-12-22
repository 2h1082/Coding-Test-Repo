#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring> // for memset

using namespace std;

// 전역 변수 설정
int N, M;
int board[55][55];
int best_ans = 0;
int dr[] = {-1, 1, 0, 0};
int dc[] = {0, 0, -1, 1};

// 가지치기를 위한 누적 합 (전체 맵에서 가장 큰 값들의 합)
int global_pref[15];

// 시작점 정렬을 위한 구조체
struct Node {
    int r, c, val, id;
};
Node sorted_nodes[2505];

// 방문 체크 배열 (전역으로 선언하여 재사용)
bool visited[2505];

// [핵심] 재귀 함수: std::vector 대신 포인터/배열 사용으로 속도 최적화
// cands: 현재 추가 가능한 후보군 목록
// len: 후보군의 길이
void solve(int count, int current_sum, int* cands, int len) {
    // 1. 가지치기: 남은 개수를 '전체 맵의 최대값들'로 채워도 기록 경신 불가면 중단
    if (current_sum + global_pref[M - count] <= best_ans) return;

    // 2. M개 선택 완료
    if (count == M) {
        if (current_sum > best_ans) best_ans = current_sum;
        return;
    }

    // 3. 후보군 순회 (Vance's Algorithm 스타일)
    for (int i = 0; i < len; ++i) {
        int u = cands[i];
        int r = u / N;
        int c = u % N;

        // 다음 재귀에 넘길 후보군 생성 (정적 배열 사용)
        // 최대 크기 예측: 현재 크기 + 3 (새 이웃) -> 50이면 충분 (M=10일 때 둘레가 크지 않음)
        int next_cands[60];
        int next_len = 0;

        // (A) 현재 선택한 후보(i)의 '뒤에 있는' 후보들만 가져감 (순열 중복 방지)
        for (int j = i + 1; j < len; ++j) {
            next_cands[next_len++] = cands[j];
        }

        // (B) 새로 추가된 노드들을 추적하기 위한 배열
        int added_nodes[4];
        int added_cnt = 0;

        // (C) 현재 칸(u)의 인접 칸 탐색
        for (int k = 0; k < 4; ++k) {
            int nr = r + dr[k];
            int nc = c + dc[k];
            
            if (nr >= 0 && nr < N && nc >= 0 && nc < N) {
                int v = nr * N + nc;
                
                // [중복 방지]
                // 1. visited가 false여야 함 (이미 선택/후보/스킵/시작점보다 작은 노드가 아님)
                if (!visited[v]) {
                    visited[v] = true;
                    next_cands[next_len++] = v;
                    added_nodes[added_cnt++] = v;
                }
            }
        }

        // 재귀 호출
        solve(count + 1, current_sum + board[r][c], next_cands, next_len);

        // [백트래킹] 이번에 새로 추가한 이웃만 visited 해제
        for (int k = 0; k < added_cnt; ++k) {
            visited[added_nodes[k]] = false;
        }
    }
}

int main() {
    // 입출력 속도 향상
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    if (!(cin >> N >> M)) return 0;

    vector<int> all_vals;
    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < N; ++j) {
            cin >> board[i][j];
            all_vals.push_back(board[i][j]);
            
            int idx = i * N + j;
            sorted_nodes[idx] = {i, j, board[i][j], idx};
        }
    }

    // 1. 누적 합 계산 (Pruning 상한선)
    sort(all_vals.rbegin(), all_vals.rend());
    global_pref[0] = 0;
    for (int i = 0; i < M; ++i) global_pref[i + 1] = global_pref[i] + all_vals[i];

    // 2. 시작점 정렬: 나무가 많은 곳부터 탐색해야 가지치기가 잘 됨 (매우 중요)
    sort(sorted_nodes, sorted_nodes + (N * N), [](const Node& a, const Node& b) {
        return a.val > b.val; // 내림차순
    });

    // 3. 모든 칸을 시작점으로 시도
    for (int i = 0; i < N * N; ++i) {
        Node& root = sorted_nodes[i];
        int start_id = root.id;

        // Visited 초기화
        // start_id보다 인덱스가 작은 칸은 절대 방문하지 않도록 미리 true 처리
        // (memset 0 후 루프보다, 그냥 전체 false 후 작은것만 true가 나을 수도 있으나,
        //  매번 초기화가 필요하므로 memset이 깔끔함)
        memset(visited, 0, sizeof(visited));
        for (int k = 0; k <= start_id; ++k) visited[k] = true;

        // 초기 후보군 생성 (시작점의 인접 칸 중 인덱스가 큰 것들)
        int initial_cands[4];
        int init_len = 0;

        for (int k = 0; k < 4; ++k) {
            int nr = root.r + dr[k];
            int nc = root.c + dc[k];
            if (nr >= 0 && nr < N && nc >= 0 && nc < N) {
                int v = nr * N + nc;
                if (v > start_id) { // 시작점보다 큰 녀석만
                    visited[v] = true;
                    initial_cands[init_len++] = v;
                }
            }
        }

        // 탐색 시작 (count=1부터 시작)
        solve(1, root.val, initial_cands, init_len);
    }

    cout << best_ans << endl;

    return 0;
}