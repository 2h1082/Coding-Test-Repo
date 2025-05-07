#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

bool CanPlaceRouters(vector<int>& x, int& c, int& dist)
{
    int count = 1;
    int last_pos = x[0];

    for (int i = 1; i < x.size(); ++i) {
        if (x[i] - last_pos >= dist) {
            count++;
            last_pos = x[i];
        }
    }

    return count >= c;
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n=0, c=0;
    cin>>n>>c;
    vector<int> x(n);
    for(int i=0;i<n;i++)
    {
        cin>>x[i];
    }
    sort(x.begin(),x.end());
    int left = 1;  // 가능한 최소 거리
    int right = x[n - 1] - x[0];  // 가능한 최대 거리
    int answer = 0;

    while (left <= right) {
        int mid = (left + right) / 2;

        if (CanPlaceRouters(x, c, mid)) {
            answer = mid;
            left = mid + 1;  // 더 큰 거리 시도
        } else {
            right = mid - 1;  // 더 작은 거리 시도
        }
    }

    cout << answer << endl;
    return 0;
}