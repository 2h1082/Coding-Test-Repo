#include <string>
#include <vector>

using namespace std;

vector<vector<int>> solution(vector<vector<int>> arr1, vector<vector<int>> arr2) {
    vector<vector<int>> answer(arr1.size(),vector<int>(arr2[0].size(),0));
    for(int i=0;i<answer.size();++i)
    {
        for(int j=0;j<answer[0].size();++j)   
        {
            for(int k=0;k<arr1[0].size();++k)
            {
                answer[i][j]+=arr1[i][k]*arr2[k][j];   
            }
        }
    }
    
    return answer;
}