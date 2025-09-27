#include <iostream>
#include <vector>
#include <map>

using namespace std;
vector<int> Preorder;

void Postorder(int Start, int End)
{
    if (Start>End) return;

    int Root=Preorder[Start];
    int Right=End+1;

    for (int i=Start+1;i<=End;++i)
    {
        if (Preorder[i]>Root)
        {
            Right=i;
            break;
        }
    }
    Postorder(Start+1,Right-1);
    Postorder(Right,End);
    cout<<Root<<" ";
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int Node=0;
    
    while(cin>>Node)
    {
        Preorder.push_back(Node);        
    }
    Postorder(0,Preorder.size()-1);
}