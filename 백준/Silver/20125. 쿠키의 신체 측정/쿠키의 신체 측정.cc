#include "bits/stdc++.h"
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    int N;
    cin>>N;
    
    vector<string> B(N);
    int HeartCol=-1, HeadRow=0;
    for(int i=0;i<N;++i)
    {
        cin>>B[i];
        auto It=B[i].find('*');
        if(HeartCol==-1 && B[i].find('*')!=string::npos)
        {
            HeartCol=It;
            HeadRow=i;
            cout<<HeadRow+2<<' '<<HeartCol+1<<'\n';
        }
    }
    int LH=0, RH=0, Mid=0, LL=0, RL=0;
    for(int i=HeartCol-1;i>=0;--i)
    {
        if(B[HeadRow+1][i]=='*') LH++;
        else                     break;
    }
    for(int i=HeartCol+1;i<N;++i)
    {
        if(B[HeadRow+1][i]=='*') RH++;
        else                     break;
    }
    for(int i=HeadRow+2;i<N;++i)
    {
        if(B[i][HeartCol]=='*') Mid++;
        else                    break;
    }
    for(int i=HeadRow+Mid+2;i<N;++i)
    {
        if(B[i][HeartCol-1]=='*') LL++;
        else                      break;
    }
    for(int i=HeadRow+Mid+2;i<N;++i)
    {
        if(B[i][HeartCol+1]=='*') RL++;
        else                      break;
    }
    cout<<LH<<' '<<RH<<' '<<Mid<<' '<<LL<<' '<<RL;
}