#include <bits/stdc++.h>
using namespace std;
vector<int> answer(2,0);
bool IsUniform(vector<vector<int>>& arr, int x, int y, int size)
{
    int pivot=arr[x][y];
    for(int i=x;i<x+size;i++)
    {
        for(int j=y;j<y+size;j++)
        {
            if(arr[i][j]!=pivot) return false;
        }
    }
    return true;
}

void Compress(vector<vector<int>>& arr, int x, int y, int size)
{
    if(IsUniform(arr,x,y,size)) 
    {
        answer[arr[x][y]]++;
        return;
    }
    int half=size/2;
    Compress(arr,x,y,half);
    Compress(arr,x,y+half,half);
    Compress(arr,x+half,y,half);
    Compress(arr,x+half,y+half,half);
}
vector<int> solution(vector<vector<int>> arr) {
    int cursize=arr.size();
    Compress(arr,0,0,arr.size());
    
    return answer;
}