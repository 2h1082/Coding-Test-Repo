#include <bits/stdc++.h>
using namespace std;

const int INF = 1e9;
int N, W;      
vector<vector<int>> DP,E; 

int SolveCase(int Mode)
{
    // Mode: 2=기본 / 1=위쪽 wrap / 0=아래쪽 wrap / -1=양쪽 wrap
    DP.assign(3,vector<int>(N+1,INF));
    DP[0][0] = DP[1][0] = DP[2][0] = 0;
    
    // 0: 위만 연결, 1: 아래만 연결, 2: 둘 다
    for (int i = 1; i <= N; ++i)
    {
        // 위쪽 처리
        if (!(i == 1 && (Mode == 1 || Mode == -1)))
        {
            DP[0][i] = min(DP[0][i], DP[2][i - 1] + 1);
            if (E[0][i - 1] + E[0][i] <= W)
                DP[0][i] = min(DP[0][i], DP[1][i - 1] + 1);
        }
        else DP[0][i] = 0;

        // 아래쪽 처리
        if (!(i == 1 && (Mode == 0 || Mode == -1)))
        {
            DP[1][i] = min(DP[1][i], DP[2][i - 1] + 1);
            if (E[1][i - 1] + E[1][i] <= W)
                DP[1][i] = min(DP[1][i], DP[0][i - 1] + 1);
        }
        else DP[1][i] = 0;

        // 위아래 모두
        if (!(i == 1 && Mode == -1))
        {
            DP[2][i] = min({DP[0][i] + 1, DP[1][i] + 1, DP[2][i]});
            if (E[0][i] + E[1][i] <= W)
                DP[2][i] = min(DP[2][i], DP[2][i - 1] + 1);
            if (i - 2 >= 0 && E[0][i - 1] + E[0][i] <= W && E[1][i - 1] + E[1][i] <= W)
                DP[2][i] = min(DP[2][i], DP[2][i - 2] + 2);
        }
        else DP[2][i] = 0;
    }

    if (Mode == 2) return DP[2][N];
    if (Mode == 1 || Mode == 0) return DP[Mode][N] + 1;
    return DP[2][N - 1] + 2;
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
        E.assign(2,vector<int>(N+1,0));
        
        for (int i = 0; i<2; ++i)
            for (int j=1;j<=N;++j)
                cin>>E[i][j];

        vector<int> Modes = {2};
        if (E[0][1] + E[0][N] <= W) Modes.push_back(1);     // 위 wrap
        if (E[1][1] + E[1][N] <= W) Modes.push_back(0);     // 아래 wrap
        if (E[0][1] + E[0][N] <= W && E[1][1] + E[1][N] <= W) Modes.push_back(-1); // 양쪽 wrap

        int Ans = INF;
        for (int Mode : Modes)
            Ans = min(Ans, SolveCase(Mode));

        cout << Ans << '\n';
    }
    return 0;
}
