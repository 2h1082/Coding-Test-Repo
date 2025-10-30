#include <bits/stdc++.h>

using namespace std;

int main()
{
    int n=0;
    cin>>n;
    vector<int> Cnt(10,0);
    
    int pos=1;
    while(n/pos>0)
    {
        int Front=n/(pos*10), Cur=n/pos%10, Back=n%pos;
        for(int i=0;i<10;++i)
        {
            Cnt[i]+=Front*pos;
            if(i<Cur)
            {
                Cnt[i]+=pos;
            }
            else if(i==Cur)
            {
                Cnt[i]+=Back+1;
            }
        }
        Cnt[0]-=pos;
        pos*=10;
    }
    for(auto& c : Cnt)
    {
        cout<<c<<" ";
    }
}