#include <iostream>
#include <vector>
#include <numeric>

using namespace std;

int Mod = 10007;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int N;
    cin >> N;

    // Dp[l][i]: 길이가 l이고 마지막 숫자가 i인 오르막 수의 개수
    vector<vector<int>> Dp(N + 1, vector<int>(10, 0));

    // 길이가 1일 때는 모든 숫자가 1개씩 존재
    for (int i = 0; i < 10; ++i) Dp[1][i] = 1;

    for (int l = 2; l <= N; ++l) {
        for (int i = 0; i < 10; ++i) {
            if (i == 0) {
                Dp[l][i] = Dp[l - 1][i] % Mod;
            } else {
                // 핵심 점화식: 이전 숫자의 누적합 활용
                Dp[l][i] = (Dp[l][i - 1] + Dp[l - 1][i]) % Mod;
            }
        }
    }

    int Ans = 0;
    for (int i = 0; i < 10; ++i) {
        Ans = (Ans + Dp[N][i]) % Mod;
    }

    cout << Ans << endl;

    return 0;
}