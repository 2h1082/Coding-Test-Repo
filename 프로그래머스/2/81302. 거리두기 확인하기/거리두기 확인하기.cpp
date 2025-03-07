#include <bits/stdc++.h>

using namespace std;

int dx[] = {1, 0, -1, 0};
int dy[] = {0, 1, 0, -1};

bool CheckManhattan(vector<string>& P, int i, int j) {
    vector<vector<bool>> visited(5, vector<bool>(5, false));
    queue<pair<pair<int, int>, int>> q; // (y, x), depth(거리)
    
    q.push({{i, j}, 0});
    visited[i][j] = true;

    while (!q.empty()) {
        auto [pos, dist] = q.front();
        auto [y, x] = pos;
        q.pop();

        if (dist >= 2) continue; // 거리가 2 이상이면 더 이상 탐색할 필요 없음

        for (int k = 0; k < 4; k++) {
            int ny = y + dy[k], nx = x + dx[k];

            if (ny < 0 || nx < 0 || ny >= 5 || nx >= 5) continue;
            if (visited[ny][nx]) continue;

            if (P[ny][nx] == 'P') return false; // 다른 사람이 거리 2 이내에 있음
            if (P[ny][nx] == 'O') {
                visited[ny][nx] = true;
                q.push({{ny, nx}, dist + 1});
            }
        }
    }
    return true;
}

vector<int> solution(vector<vector<string>> places) {
    vector<int> answer;

    for (auto& P : places) {
        bool isValid = true;

        for (int i = 0; i < 5 && isValid; i++) {
            for (int j = 0; j < 5 && isValid; j++) {
                if (P[i][j] == 'P') {
                    if (!CheckManhattan(P, i, j)) {
                        isValid = false;
                        break;
                    }
                }
            }
        }
        answer.push_back(isValid ? 1 : 0);
    }
    return answer;
}
