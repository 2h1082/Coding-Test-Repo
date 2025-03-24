#include <vector>
#include <climits>
#include <iostream>
#include <algorithm>
using namespace std;

int main() {
    int N;
    cin >> N;
    vector<vector<int>> S(N, vector<int>(N));
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            cin >> S[i][j];
        }
    }

    vector<bool> Team(N, false);
    for (int i = 0; i < N / 2; i++) {
        Team[i] = true; // 초기 팀 설정
    }

    int Min = INT_MAX;
    do {
        int sumTrue = 0, sumFalse = 0;
        for (int i = 0; i < N; i++) {
            for (int j = i + 1; j < N; j++) { // 대각선 기준으로만 계산
                if (Team[i] && Team[j]) {
                    sumTrue += S[i][j] + S[j][i];
                } else if (!Team[i] && !Team[j]) {
                    sumFalse += S[i][j] + S[j][i];
                }
            }
        }
        Min = min(Min, abs(sumTrue - sumFalse));
    } while (prev_permutation(Team.begin(), Team.end())); // 다음 조합 생성

    cout << Min << endl;
    return 0;
}