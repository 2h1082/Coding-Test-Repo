#include <iostream>
#include <vector>
#include <climits>

using namespace std;
vector<int> Items;
vector<vector<int>> Graph;
int MaxValue=0;
int N=0,M=0,R=0;

int main()
{
    cin>>N>>M>>R;
    Items.assign(N+1,0);
    Graph.assign(N+1,vector<int>(N+1,INT_MAX));
    for(int i=1;i<=N;++i)
    {
        cin>>Items[i];
    }
    for(int i=1;i<=R;++i)
    {
        int F, T, C;
        cin>>F>>T>>C;
        Graph[F][T]=C;
        Graph[T][F]=C;
    }
    for (int k=1;k<=N;++k)
    {
        for (int i=1;i<=N;++i)
        {
            for (int j=1;j<=N;++j)
            {
                if (Graph[i][k]!=INT_MAX && Graph[k][j]!=INT_MAX&&i!=j)
                {
                    Graph[i][j]=min(Graph[i][j],Graph[i][k]+Graph[k][j]);
                }
            }
        }        
    }
    for(int i=1;i<=N;++i)
    {
        int Sum=Items[i];
        for (int j=1;j<=N;++j)
        {
            if (Graph[i][j]<=M)
            {
                Sum+=Items[j];
            }
        }
        MaxValue=max(Sum,MaxValue);       
    }
    cout<<MaxValue;
}