#include <iostream>
#include <unordered_set>

using namespace std;
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int N=0;
    cin>>N;
    unordered_set<int> S;
    for(int i=0;i<N;i++)
    {
        string Command;
        cin>>Command;
        int Num=0;
        if (Command=="add")
        {
            cin>>Num;
            S.insert(Num);
        }
        else if (Command=="remove")
        {
            cin>>Num;
            S.erase(Num);
        }
        else if (Command=="check")
        {
            cin>>Num;
            if (S.find(Num)!=S.end())
            {
                cout<<"1\n";
            }
            else
            {
                cout<<"0\n";
            }
        }
        else if (Command=="toggle")
        {
            cin>>Num;
            if (S.find(Num)!=S.end())
            {
                S.erase(Num);
            }
            else
            {
                S.insert(Num);
            }
        }
        else if (Command=="all")
        {
            for (int j=1;j<=20;++j)
            {
                S.insert(j);
            }
        }
        else if (Command=="empty")
        {
            S.clear();
        }
    }
}