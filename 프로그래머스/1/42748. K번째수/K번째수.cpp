#include <string>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> solution(vector<int> Array, vector<vector<int>> Commands) 
{
    vector<int> Ans;
    for(auto& C : Commands)
    {
        int i=C[0], j=C[1], k=C[2];
        vector<int> Temp(Array.begin()+i-1,Array.begin()+j);
        sort(Temp.begin(),Temp.end());
        Ans.push_back(Temp[k-1]);
    }
    
    return Ans;
}