#include <bits/stdc++.h>

using namespace std;

vector<string> solution(vector<vector<int>> line) {
    vector<pair<long long, long long>> points;
    long long minX=LLONG_MAX, minY=LLONG_MAX;
    long long maxX=LLONG_MIN, maxY=LLONG_MIN;
    for(int i=0;i<line.size();i++)
    {
        for(int j=i+1;j<line.size();j++)
        {
            long long A1=line[i][0], B1=line[i][1], C1=line[i][2];
            long long A2=line[j][0], B2=line[j][1], C2=line[j][2];
            
            long long det=A1*B2-A2*B1;
            if(det==0) continue;
            long long x=C2*B1-C1*B2;
            long long y=A2*C1-A1*C2;
            if(x%det!=0||y%det!=0) continue;
            x/=det;
            y/=det;
            points.push_back({x,y});
            minX=min(minX,x);
            minY=min(minY,y);
            maxX=max(maxX,x);
            maxY=max(maxY,y);
        }
    }
    long long width=maxX-minX+1;
    long long height=maxY-minY+1;
    vector<string> answer(height,string(width,'.'));
    
    for(auto [x,y]:points)
    {
        int row=maxY-y;
        int col=x-minX;
        answer[row][col]='*';
    }
    
    return answer;
}