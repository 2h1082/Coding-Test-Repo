#include <bits/stdc++.h>

using namespace std;

int solution(vector<vector<int>> data, int col, int row_begin, int row_end) {
    int answer = 0;
    vector<int> S(data.size()+1,0);
    
    sort(data.begin(),data.end(),[col](vector<int> a, vector<int> b){
        if(a[col-1]==b[col-1])
        {
           return a[0]>b[0];
        }
        else
        {
            return a[col-1]<b[col-1];
        }
    });
    
    for(int i=row_begin-1;i<row_end;i++)
    {
        for(int j=0;j<data[0].size();j++)
        {
            S[i]+=data[i][j]%(i+1);
        }
        answer^=S[i];
    }
    return answer;
}