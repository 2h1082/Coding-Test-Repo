#include <vector>
#include <iostream>
#include <limits.h>
using namespace std;
int Min=INT_MAX;
int Max=INT_MIN;
void DFS(vector<int>& op, vector<int>& num, int n, int idx, int result)
{
    if(n==idx)
    {
        Max=max(result,Max);
        Min=min(result,Min);
        return;
    }
    for(int i=0;i<4;i++)
    {
        if(op[i]>0)
        {
            op[i]--;
            if(i==0) DFS(op,num,n,idx+1,result+num[idx]);
            else if(i==1) DFS(op,num,n,idx+1,result-num[idx]);
            else if(i==2) DFS(op,num,n,idx+1,result*num[idx]);
            else if(i==3) DFS(op,num,n,idx+1,result/num[idx]);
            op[i]++;
        }
    }
}
int main()
{
    int n;
    cin>>n;
    vector<int> num(n,0);
    for(int i=0;i<n;i++)
    {
        cin>>num[i];
    }
    vector<int> op(4,0);
    for(int i=0;i<4;i++)
    {
        cin>>op[i];
    }
    DFS(op,num,n,1,num[0]);
    cout<<Max<<"\n"<<Min<<"\n";
    return 0;
}