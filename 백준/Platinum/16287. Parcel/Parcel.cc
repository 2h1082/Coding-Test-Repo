#include <bits/stdc++.h>

using namespace std;

int main()
{
    int W=0, A=0;
    cin>>W>>A;
    
    vector<int> Obj(A,0);
    vector<int> Exist(W+1,-1);
    for(auto& o : Obj)
    {
        cin>>o;
    }
    
    for(int i=0;i<A;++i)
    {
        for(int j=i+1;j<A;++j)
        {
            int Sum=Obj[i]+Obj[j];
            if(Sum>W) continue;
            
            if(Exist[W-Sum]!=-1) 
            {
                cout<<"YES";
                return 0;
            }
        }
        for(int k=0;k<i;++k)
        {
            int Sum=Obj[i]+Obj[k];
            if(Sum<=W && Exist[Sum]==-1)
            {
                Exist[Sum]=i;
            }
        }
    }
    cout<<"NO";
}