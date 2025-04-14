#include <bits/stdc++.h>
using namespace std;

bool IsTarget(int x, int y, bool rotate, int size) {
    if (!rotate && x == size - 2 && y == size - 1) return true;
    if (rotate && x == size - 1 && y == size - 2) return true;
    return false;
}

int solution(vector<vector<int>> board) {
    int size = board.size();
    queue<tuple<int, int, int, bool>> q;  // x, y, move count, rotate
    vector<vector<vector<bool>>> visited(size, vector<vector<bool>>(size, vector<bool>(2, false)));

    q.push({0, 0, 0, false});
    visited[0][0][0] = true;

    vector<int> dx = {1, -1, 0, 0};
    vector<int> dy = {0, 0, 1, -1};

    while (!q.empty()) {
        auto [x, y, cnt, rotate] = q.front();
        q.pop();

        if (IsTarget(x, y, rotate, size)) return cnt;

        // 이동
        for (int i = 0; i < 4; i++) {
            int nx = x + dx[i];
            int ny = y + dy[i];

            if (!rotate) { // 가로
                if (nx >= 0 && nx + 1 < size && ny >= 0 && ny < size &&
                    board[ny][nx] == 0 && board[ny][nx + 1] == 0 &&
                    !visited[ny][nx][0]) {
                    visited[ny][nx][0] = true;
                    q.push({nx, ny, cnt + 1, false});
                }
            } else { // 세로
                if (nx >= 0 && nx < size && ny >= 0 && ny + 1 < size &&
                    board[ny][nx] == 0 && board[ny + 1][nx] == 0 &&
                    !visited[ny][nx][1]) {
                    visited[ny][nx][1] = true;
                    q.push({nx, ny, cnt + 1, true});
                }
            }
        }

        // 회전
        if (!rotate)
        { // 가로 -> 세로
            // 아래로 회전
            if (y + 1 < size &&board[y + 1][x] == 0 && board[y + 1][x + 1] == 0) 
            {
                if (!visited[y][x][1]) 
                {
                    visited[y][x][1] = true;
                    q.push({x, y, cnt + 1, true});
                }
                if (!visited[y][x + 1][1]) 
                {
                    visited[y][x + 1][1] = true;
                    q.push({x + 1, y, cnt + 1, true});
                }
            }
            // 위로 회전
            if (y - 1 >= 0 &&board[y - 1][x] == 0 && board[y - 1][x + 1] == 0) 
            {
                if (!visited[y - 1][x][1]) 
                {
                    visited[y - 1][x][1] = true;
                    q.push({x, y - 1, cnt + 1, true});
                }
                if (!visited[y - 1][x + 1][1]) 
                {
                    visited[y - 1][x + 1][1] = true;
                    q.push({x + 1, y - 1, cnt + 1, true});
                }
            }
        }
        else 
        { // 세로 -> 가로
            // 오른쪽 회전
            if (x + 1 < size &&board[y][x + 1] == 0 && board[y + 1][x + 1] == 0) 
            {
                if (!visited[y][x][0]) 
                {
                    visited[y][x][0] = true;
                    q.push({x, y, cnt + 1, false});
                }
                if (!visited[y + 1][x][0]) 
                {
                    visited[y + 1][x][0] = true;
                    q.push({x, y + 1, cnt + 1, false});
                }
            }
            // 왼쪽 회전
            if (x - 1 >= 0 &&board[y][x - 1] == 0 && board[y + 1][x - 1] == 0) 
            {
                if (!visited[y][x - 1][0]) 
                {
                    visited[y][x - 1][0] = true;
                    q.push({x - 1, y, cnt + 1, false});
                }
                if (!visited[y + 1][x - 1][0]) 
                {
                    visited[y + 1][x - 1][0] = true;
                    q.push({x - 1, y + 1, cnt + 1, false});
                }
            }
        }
    }

    return 0;
}
