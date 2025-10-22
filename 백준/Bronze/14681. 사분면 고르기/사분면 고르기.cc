#include <bits/stdc++.h>

using namespace std;

int main()
{
    int x,y;
    cin>>x>>y;
    int Res=1;
    if(x<0&&y>0) Res=2;
    else if(x<0&&y<0) Res=3;
    else if(x>0&&y<0) Res=4;
    cout<<Res;
}