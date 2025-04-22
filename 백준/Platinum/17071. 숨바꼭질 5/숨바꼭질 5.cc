#include <iostream>
#include <queue>
#include <vector>

using namespace std;

const int MAX=500001;
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    int n, k;
    cin >> n >> k;
    
    vector<vector<bool>> visited(2,vector<bool>(MAX,false));
    queue<int> q;
    q.push(n);
    visited[0][n] = true;
    int time=0;
    while (!q.empty())
    {
        int brother=k+time*(time+1)/2;
        if (brother>=MAX) break;
        if (visited[time%2][brother])
        {
            cout<<time<<"\n";
            return 0;
        }
        int size=q.size();
        time++;
        for (int i=0;i<size;i++)
        {
            int cur=q.front();
            q.pop();
            for (int next:{cur-1,cur+1,cur*2})
            {
                if (next>=0&&next<MAX&&!visited[time%2][next])
                {
                    visited[time%2][next]=true;
                    q.push(next);
                }
            }
        }
    }
    
    cout << "-1\n"; // 따라잡을 수 없는 경우
    return 0;
}