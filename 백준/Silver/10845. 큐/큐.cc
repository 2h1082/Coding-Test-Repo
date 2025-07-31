#include <queue>
#include <iostream>

using namespace std;
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int N=0;
    cin>>N;
    queue<int> q;
    for(int i=0;i<N;++i)
    {
        string Command;
        cin>>Command;
        if(Command=="push")
        {
            int Num=0;
            cin>>Num;
            q.push(Num);
        }
        else if(Command=="pop")
        {
            int Num=-1;
            if(!q.empty())
            {
                Num=q.front();
                q.pop();
            }
            cout<<Num<<"\n";
        }
        else if(Command=="size")
        {
            cout<<q.size()<<"\n";
        }
        else if(Command=="empty")
        {
            int Result=q.empty()?1:0;
            cout<<Result<<"\n";
        }
        else if(Command=="front")
        {
            int Num=-1;
            if(!q.empty())
            {
                Num=q.front();
            }
            cout<<Num<<"\n";
        }
        else if(Command=="back")
        {
            int Num=-1;
            if(!q.empty())
            {
                Num=q.back();
            }
            cout<<Num<<"\n";
        }
    }
}