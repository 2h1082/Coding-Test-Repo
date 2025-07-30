#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
int main()
{
    int N=0;
    cin>>N;
    vector<string> Words(N);
    for (int i=0;i<N;++i)
    {
        cin>>Words[i];
    }
    sort(Words.begin(),Words.end(),[&](const string& a, const string& b)
    {
        if (a.length()!=b.length()) return a.length()<b.length();
        return a<b;
    });
    auto NewEnd=unique(Words.begin(),Words.end());
    Words.erase(NewEnd,Words.end());
    for (auto& word:Words)
    {
        cout<<word<<endl;
    }
}
