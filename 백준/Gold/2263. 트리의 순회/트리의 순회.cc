#include <bits/stdc++.h>

using namespace std;
vector<int> In, Post;
unordered_map<int,int> InIdx;

void Preorder(int InStart, int InEnd, int PostStart, int PostEnd)
{
    if(InStart>InEnd || PostStart>PostEnd) return;
    
    int Root=Post[PostEnd];
    int RootIdx=InIdx[Root];
    cout<<Root<<" ";
    
    int LeftSize=RootIdx-InStart;
    Preorder(InStart,RootIdx-1,PostStart,PostStart+LeftSize-1);
    Preorder(RootIdx+1,InEnd,PostStart+LeftSize,PostEnd-1);
}
int main()
{
    int N=0;
    cin>>N;
    
    In.assign(N,0);
    Post.assign(N,0);
    
    for(auto& i : In)
    {
        cin>>i;
    }
    for(auto& i : Post)
    {
        cin>>i;
    }
    int Root=Post[N-1];
    for(int i=0;i<N;++i)
    {
        InIdx[In[i]]=i;
    }
    Preorder(0,N-1,0,N-1);
}