#include <iostream>
#include <queue>
#include <vector>

using namespace std;
int main()
{
    int N=0;
    cin>>N;
    priority_queue<vector<int>,vector<vector<int>>, greater<>> q;
    while(N--)
    {
        int Start=0, End=0;
        cin>>Start>>End;
        q.push({End,Start});
    }
    int Count=0;
    int PrevEnd=0;
    while(!q.empty())
    {
        int CurEnd=q.top()[0];
        int CurStart=q.top()[1];
        q.pop();
        if(PrevEnd<=CurStart)
        {
            PrevEnd=CurEnd;
            Count++;
        }
    }
    cout<<Count;
}