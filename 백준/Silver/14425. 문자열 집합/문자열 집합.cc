#include <set>
#include <iostream>
using namespace std;
int main(int argc, char* argv[])
{
    int n=0, m=0;
    set<string> S;
    cin>>n>>m;
    for (int i=0;i<n;i++)
    {
        string str;
        cin>>str;
        S.insert(str);
    }
    int answer=0;
    for (int j=0;j<m;j++)
    {
        string in;
        cin>>in;
        if (S.find(in)!=S.end())
        {
            answer++;
        }
    }
    cout<<answer<<endl;
    return 0;
}