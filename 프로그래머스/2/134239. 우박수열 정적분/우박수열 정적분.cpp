#include <bits/stdc++.h>

using namespace std;

double ComputeArea(vector<int>& graph, int start, int end)
{
    double area=0;
    for(int i=start;i<end;i++)
    {
        area+=((double)graph[i]+graph[i+1])/2;
    }
    return area;
}
vector<double> solution(int k, vector<vector<int>> ranges) {
    vector<double> answer;
    vector<int> graph(1,k);
    while(k!=1)
    {
        if(k%2==0) k/=2;
        else if(k%2!=0) k=k*3+1;
        graph.push_back(k);
    }
    int n=graph.size()-1;
    for(auto v : ranges)
    {
        int start=v[0];
        int end=n+v[1];
        if(start>end)
        {
            answer.push_back(-1);
        }
        else
        {
            double area=ComputeArea(graph,start,end);
            answer.push_back(area);
        }
    }
    return answer;
}