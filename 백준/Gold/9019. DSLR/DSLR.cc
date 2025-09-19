#include <iostream>
#include <queue>
#include <string>

using namespace std;
char Command[4]={'D','S','L','R'};
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int T=0;
    cin>>T;
    while(T--)
    {
        int Start, Target;
        cin>>Start>>Target;
        queue<pair<int,string>> q;
        vector<bool> Visited(10001,false);
        q.push({Start,""});
        Visited[Start]=true;
        while(!q.empty())
        {
            int Cur=q.front().first;
            string CurCommand=q.front().second;
            if(Cur==Target)
            {
                cout<<CurCommand<<"\n";
                break;
            }
            q.pop();
            for(int i=0;i<4;++i)
            {
                int Next=Cur;
                string AdditionalCom;
                if(Command[i]=='D')
                {
                    Next=Next*2%10000;
                    AdditionalCom="D";
                }
                else if(Command[i]=='S')
                {
                    Next= (Next-1) <0 ? 9999 : Next-1;
                    AdditionalCom="S";
                }
                else if(Command[i]=='L')
                {
                    int Shifted=Next/1000;
                    Next=(Next%1000)*10+Shifted;
                    AdditionalCom="L";
                }
                else if(Command[i]=='R')
                {
                    int Shifted=Next%10;
                    Next=(Next/10)+(1000*Shifted);
                    AdditionalCom="R";
                }
                if(!Visited[Next])
                {
                    q.push({Next,CurCommand+AdditionalCom});
                    Visited[Next]=true;
                }
            }
        }
    }
}