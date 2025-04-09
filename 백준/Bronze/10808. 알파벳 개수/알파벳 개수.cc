#include <iostream>
#include <vector>
#include <string>

using namespace std;
int main()
{
    vector<int> m(26,0);
    string s;
    cin>>s;
    for(auto& c:s)
    {
        m[c-'a']++;
    }
    for(int i=0;i<m.size();i++)
    {
        cout<<m[i]<<" ";
    }
}