#include <bits/stdc++.h>
using namespace std;

const int INF = 1e9;
int N, W;
int A[2][10005];      // A[0][i] = 위, A[1][i] = 아래
int dp[3][10005];     // 0: 위만 연결, 1: 아래만 연결, 2: 둘 다

void Init(int n)
{
    for (int i = 0; i <= n; ++i)
        for (int j = 0; j < 3; ++j)
            dp[j][i] = INF;
}

int SolveCase(int mode)
{
    // mode: 2=기본 / 1=위쪽 wrap / 0=아래쪽 wrap / -1=양쪽 wrap
    Init(N);
    dp[0][0] = dp[1][0] = dp[2][0] = 0;

    for (int i = 1; i <= N; ++i)
    {
        // 위쪽 처리
        if (!(i == 1 && (mode == 1 || mode == -1)))
        {
            dp[0][i] = min(dp[0][i], dp[2][i - 1] + 1);
            if (A[0][i - 1] + A[0][i] <= W)
                dp[0][i] = min(dp[0][i], dp[1][i - 1] + 1);
        }
        else dp[0][i] = 0;

        // 아래쪽 처리
        if (!(i == 1 && (mode == 0 || mode == -1)))
        {
            dp[1][i] = min(dp[1][i], dp[2][i - 1] + 1);
            if (A[1][i - 1] + A[1][i] <= W)
                dp[1][i] = min(dp[1][i], dp[0][i - 1] + 1);
        }
        else dp[1][i] = 0;

        // 위아래 모두
        if (!(i == 1 && mode == -1))
        {
            dp[2][i] = min({dp[0][i] + 1, dp[1][i] + 1, dp[2][i]});
            if (A[0][i] + A[1][i] <= W)
                dp[2][i] = min(dp[2][i], dp[2][i - 1] + 1);
            if (i - 2 >= 0 && A[0][i - 1] + A[0][i] <= W && A[1][i - 1] + A[1][i] <= W)
                dp[2][i] = min(dp[2][i], dp[2][i - 2] + 2);
        }
        else dp[2][i] = 0;
    }

    if (mode == 2) return dp[2][N];
    if (mode == 1 || mode == 0) return dp[mode][N] + 1;
    return dp[2][N - 1] + 2;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int T;
    cin >> T;

    while (T--)
    {
        cin >> N >> W;
        for (int j = 0; j < 2; ++j)
            for (int i = 1; i <= N; ++i)
                cin >> A[j][i];

        vector<int> modes = {2};
        if (A[0][1] + A[0][N] <= W) modes.push_back(1);     // 위 wrap
        if (A[1][1] + A[1][N] <= W) modes.push_back(0);     // 아래 wrap
        if (A[0][1] + A[0][N] <= W && A[1][1] + A[1][N] <= W) modes.push_back(-1); // 양쪽 wrap

        int ans = INF;
        for (int mode : modes)
            ans = min(ans, SolveCase(mode));

        cout << ans << '\n';
    }
    return 0;
}