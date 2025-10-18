#include <bits/stdc++.h>
using namespace std;
using ll = long long;

// 1부터 N까지의 1의 개수를 구하는 함수
ll countOnes(ll N) {
    if (N < 0) return 0;
    ll res = 0;
    for (ll bit = 0; bit < 63; ++bit) { // 0~62비트 (long long 최대 10^18)
        ll cycle = 1LL << (bit + 1);
        ll full_cycles = (N + 1) / cycle;
        ll remainder = (N + 1) % cycle;
        res += full_cycles * (1LL << bit);
        if (remainder > (1LL << bit))
            res += remainder - (1LL << bit);
    }
    return res;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    ll A, B;
    cin >> A >> B;
    cout << countOnes(B) - countOnes(A - 1) << "\n";
    return 0;
}
