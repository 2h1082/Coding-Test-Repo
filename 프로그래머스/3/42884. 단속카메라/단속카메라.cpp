#include "bits/stdc++.h"
using namespace std;

int solution(vector<vector<int>> R) {
    int Ans = 1;
    sort(R.begin(),R.end(),[](const vector<int>& a, const vector<int>& b){
        if(a[1]==b[1]) return a[0] < b[0];
        return a[1] < b[1];
    });
    int Cur=R[0][1];
    for(int i=1;i<R.size();++i)
    {
        int S=R[i][0], E=R[i][1];
        if(Cur < S)
        {
            Ans++;
            Cur=E;
        }
    }
    
    return Ans;
}