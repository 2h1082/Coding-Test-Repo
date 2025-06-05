#include <string>
#include <vector>
#include <unordered_set>

using namespace std;

int solution(int N, int number) {
    vector<unordered_set<int>> dp(9);
    
    int concatenated=0;
    for(int i=1;i<9;i++)
    {
        concatenated=concatenated*10+N;
        dp[i].insert(concatenated);
    }
    for(int i=1;i<9;i++)
    {
        if(dp[i].count(number)) return i;
        
        for(int j=1;j<i;++j)
        {
            int k=i-j;
            for(int a:dp[j])
            {
                for(int b:dp[k])
                {
                    dp[i].insert(a+b);
                    dp[i].insert(a-b);
                    dp[i].insert(a*b);
                    if(b) dp[i].insert(a/b);
                }
            }
        }
        if(dp[i].count(number)) return i;
    }
    return -1;
}