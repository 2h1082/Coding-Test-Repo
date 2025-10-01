#include <iostream>
#include <climits>
#include <vector>

using namespace std;
int main()
{
    int TC=0;
    cin>>TC;
    while(TC--)
    {
        int N=0,M=0,W=0;
        cin>>N>>M>>W;
        vector<vector<pair<int,int>>> Node(N+1,vector<pair<int,int>>());
        for(int i=1;i<=N;++i)
        {
            Node[0].push_back({0,i});
        }
        while(M--)
        {
            int S,E,T;
            cin>>S>>E>>T;
            Node[S].push_back({T,E}); // Cost, EndNode
            Node[E].push_back({T,S}); // Cost, EndNode
        }
        while(W--)
        {
            int S,E,T;
            cin>>S>>E>>T;
            Node[S].push_back({-T,E});
        }
        vector<long long> Dist(N+1,LLONG_MAX);
        Dist[0]=0;
        for(int i=0;i<N;++i)
        {
            for(int Cur=0;Cur<=N;++Cur)
            {
                for(auto NextInfo : Node[Cur])
                {
                    if(Dist[Cur]!=LLONG_MAX)
                    {
                        int Next=NextInfo.second;
                        int NextCost=Dist[Cur]+NextInfo.first;
                        if(Dist[Next]>NextCost)
                        {
                            Dist[Next]=NextCost;
                        }
                    }
                }
            }
        }
        bool bIsNegativeCycle=false;
        for(int Cur=0;Cur<=N;++Cur)
        {
            for(auto NextInfo : Node[Cur])
                {
                    if(Dist[Cur]!=LLONG_MAX)
                    {
                        int Next=NextInfo.second;
                        int NextCost=Dist[Cur]+NextInfo.first;
                        if(Dist[Next]>NextCost)
                        {
                            Dist[Next]=NextCost;
                            bIsNegativeCycle=true;
                            break;
                        }
                    }
                }
        }
        string Res= bIsNegativeCycle ? "YES" : "NO";
        cout<<Res<<"\n";
    }
}