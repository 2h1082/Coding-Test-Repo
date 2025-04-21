#include <string>
#include <iostream>
#include <set>
using namespace std;
int main(int argc, char* argv[])
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int t=0;
    cin>>t;
    for(int i=0;i<t;i++)
    {
        int n;
        cin>>n;
        set<string> L;
        for (int j=0;j<n;j++)
        {
            string s;
            cin>>s;
            L.insert(s);
        }
        bool flag=true;
        for (auto it=L.begin();it!=L.end();it++)
        {
            auto next=it;
            next++;
            if (next!=L.end()&&next->size()>=it->size()&&*it==next->substr(0,it->size()))
            {
                flag=false;
                break;
            }
        }
        string answer=flag?"YES":"NO";
        cout<<answer<<endl;
    }
    return 0;
}
