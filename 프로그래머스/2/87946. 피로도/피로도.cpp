#include <string>
#include <vector>

using namespace std;

int MaxCount=0;

void VisitDungeon(int k, vector<vector<int>> dungeons, vector<bool> visit, int count)
{
    MaxCount=max(MaxCount,count);
    
    for(int i=0;i<dungeons.size();++i)
    {
        if(!visit[i]&&dungeons[i][0]<=k)
        {
            visit[i]=true;
            VisitDungeon(k-dungeons[i][1],dungeons,visit,count+1);
            visit[i]=false;
        }
    }
}


int solution(int k, vector<vector<int>> dungeons) {
    vector<bool> visit(dungeons.size(),false);
    VisitDungeon(k,dungeons,visit,0);
    
    return MaxCount;
}