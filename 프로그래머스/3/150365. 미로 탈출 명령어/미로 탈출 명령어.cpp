#include <string>
#include <vector>

using namespace std;

bool found=false;
string answer = "";
int targetX, targetY;
int RowSize, ColSize;
vector<char> dir={'d','l','r','u'};
vector<int> dx={1,0,0,-1};
vector<int> dy={0,-1,1,0};

void DFS(int x, int y, int remain, string& path)
{
    if(found) return;
    int dist=abs(x-targetX)+abs(y-targetY);
    if(dist>remain) return;
    if((remain-dist)%2!=0) return; //2면 들렀다가 나와서 다시 들어가면 도착 가능(+2)
    
    if(remain==0)
    {
        if(x==targetX&&y==targetY)
        {
            answer=path;
            found=true;
        }
        return;
    }
    for(int i=0;i<4;i++)
    {
        int nx=x+dx[i], ny=y+dy[i];
        if(nx<1||nx>RowSize||ny<1||ny>ColSize) continue;
        path.push_back(dir[i]);
        DFS(nx,ny,remain-1,path);
        path.pop_back();
    }
}

string solution(int n, int m, int x, int y, int r, int c, int k) {
    targetX=r;
    targetY=c;
    RowSize=n;
    ColSize=m;
    string path="";
    DFS(x,y,k,path);
    if(!found) return "impossible";
    return answer;
}