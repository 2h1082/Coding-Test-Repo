#include <iostream>
#include <vector>

using namespace std;
int main()
{
    vector<int> Alpha(26, -1);
    string Word;
    cin>>Word;
    
    for(int i=0;i<Word.size();++i)
    {
        int& E=Alpha[Word[i]-'a'];
        E = E==-1 ? i : E;
    }
    for(auto& C : Alpha)
    {
        cout<<C<<" ";
    }
}