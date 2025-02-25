#include <bits/stdc++.h>

using namespace std;

void findFood(vector<string>& maps, int row, int column, int& sum,vector<vector<bool>>& visited)
{
    if(row<0 || column<0 || row>=maps.size() || column>=maps[0].size() || visited[row][column] || maps[row][column]=='X') return;
    
    visited[row][column]=true;
    sum+=maps[row][column]-'0';
    
    findFood(maps,row+1,column,sum,visited);
    findFood(maps,row,column+1,sum,visited);
    findFood(maps,row,column-1,sum,visited);
    findFood(maps,row-1,column,sum,visited);
}

vector<int> solution(vector<string> maps) {
    vector<int> answer;
    vector<vector<bool>> visited(maps.size(),vector<bool>(maps[0].size(),false));
    for(int i=0;i<maps.size();i++)
    {
        for(int j=0;j<maps[0].size();j++)
        {
            if(maps[i][j]!='X' && !visited[i][j])
            {
                int sum=0;
                findFood(maps,i,j,sum,visited);
                answer.push_back(sum);
            }
        }
    }
    sort(answer.begin(),answer.end());
    if(answer.empty()) answer.push_back(-1);
    return answer;
}