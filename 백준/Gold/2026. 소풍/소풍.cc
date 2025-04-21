#include <iostream>
#include <map>
#include <vector>
#include <functional>

using namespace std;
int main(int argc, char* argv[])
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int k,n,f;
    cin>>k>>n>>f;
    vector<vector<bool>> adj(n+1,vector<bool>(n+1,false));
    for (int i=0;i<f;i++)
    {
        int from,to;
        cin>>from>>to;
        adj[from][to]=adj[to][from]=true;
    }
    vector<bool> visited(n+1,false);
    vector<int> answer;
    bool found=false;
    function<void(int,int,vector<int>&)> DFS=[&](int a, int cur, vector<int>& s)
    {
        if (found) return;
        if (a==0)
        {
            answer=s;
            found=true;
            return;
        }
        for (int next=cur+1;next<=n;next++)
        {
            if (!visited[next])
            {
                bool valid=true;
                for (int member:s)
                {
                    if (!adj[member][next])
                    {
                        valid=false;
                        break;
                    }
                }
                if (valid)
                {
                    visited[next]=true;
                    s.push_back(next);
                    DFS(a-1,next,s);
                    s.pop_back();
                    visited[next]=false;
                }
            }
        }
        
    };
    for (int i=1;i<=n;i++)
    {
        if (found) break;
        vector<int> s;
        visited[i]=true;
        s.push_back(i);
        DFS(k-1,i,s);
        s.pop_back();
        visited[i]=false;
    }
    if (answer.empty())
    {
        cout<<-1<<"\n";
        return 0;
    }
    for (int i=0;i<k;i++)
    {
        cout<<answer[i]<<"\n";
    }
    return 0;
}
