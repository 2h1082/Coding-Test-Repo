#include <bits/stdc++.h>

using namespace std;



vector<int> solution(int n) {
    vector<int> answer;
    vector<vector<int>> arr(n);
    for(int i=0;i<n;i++)
    {
        arr[i].resize(i+1);
    }
    int cnt=1;
    int column=0;
    int row=-1;
    while(n>0)
    {
        for(int i=0;i<n;i++)
        {
            row++;
            arr[row][column]=cnt++;
        }
        n--;
        for(int i=0;i<n;i++)
        {
            column++;
            arr[row][column]=cnt++;
        }
        n--;
        for(int i=0;i<n;i++)
        {
            column--;
            row--;
            arr[row][column]=cnt++;
        }
        n--;
    }
    for(int i=0;i<arr.size();i++)
    {
        for(int j=0;j<arr[i].size();j++)
        {
            answer.push_back(arr[i][j]);
        }
    }
    return answer;
}