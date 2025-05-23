#include <string>
#include <vector>

using namespace std;

int solution(int n, vector<vector<int>> results) {
    int answer = 0;
    vector<vector<bool>> CanWin(n+1,vector<bool>(n+1,false));
    //워셜 플로이드
    for(auto& r : results)
    {
        CanWin[r[0]][r[1]]=true;
    }
    
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=n;j++)
        {
            for(int k=1;k<=n;k++)
            {
                if(CanWin[j][i]&&CanWin[i][k]) CanWin[j][k]=true;
            }
        }
    }
    
    for(int i=1;i<=n;i++)
    {
        int Win=0, Lose=0;
        for(int j=1;j<=n;j++)
        {
            if(CanWin[i][j]) Win++;
            if(CanWin[j][i]) Lose++;
        }
        if((Win+Lose)==n-1) answer++;
    }
    
    return answer;
}