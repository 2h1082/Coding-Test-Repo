#include <bits/stdc++.h>

using namespace std;

int N=0;
struct Node
{
    map<string, Node*> Child;
};

void DFS(Node* Cur, int Depth)
{
    for(auto& [Name,Nxt] : Cur->Child)
    {
        for(int i=0;i<Depth;++i)
        {
            cout<<"--";
        }
        cout<<Name<<"\n";
        DFS(Nxt,Depth+1);
    }
}
int main()
{
    cin>>N;
    vector<vector<int>> Foods(N);
    Node Root;
    for(int i=0;i<N;++i)
    {
        Node* Cur=&Root;
        int Num=0;
        cin>>Num;
        while(Num--)
        {
            string Nxt;
            cin>>Nxt;
            if(Cur->Child.find(Nxt)==Cur->Child.end())
            {
                Cur->Child[Nxt]=new Node();
            }
            Cur=Cur->Child[Nxt];
        }
    }
    DFS(&Root,0);
}