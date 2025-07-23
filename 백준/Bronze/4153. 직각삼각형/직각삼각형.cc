#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
int main()
{
    while(1)
    {
        vector<int> Len(3);
        cin>>Len[0]>>Len[1]>>Len[2];
        
        if(Len[0]==0 && Len[1]==0 && Len[2]==0) break;
        
        sort(Len.begin(),Len.end());
        string Result = (Len[0]*Len[0]+Len[1]*Len[1]) == Len[2]*Len[2] ? "right" : "wrong";
        cout<<Result<<"\n";
    }
}