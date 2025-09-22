#include <iostream>
#include <map>

using namespace std;

map<char,pair<char,char>> Tree;
string Pre,In,Post;

void Traversal(char Cur)
{
    Pre+=Cur;
    pair<char,char> Child=Tree[Cur];
    if(Child.first!='.')
    {
        Traversal(Child.first);
    }
    In+=Cur;
    if(Child.second!='.')
    {
        Traversal(Child.second);
    }
    Post+=Cur;
}
int main()
{
    int N=0;
    cin>>N;
    while(N--)
    {
        char Parent,Left,Right;
        cin>>Parent>>Left>>Right;
        Tree[Parent]={Left,Right};
    }
    Traversal('A');
    cout<<Pre<<"\n"<<In<<"\n"<<Post;
}