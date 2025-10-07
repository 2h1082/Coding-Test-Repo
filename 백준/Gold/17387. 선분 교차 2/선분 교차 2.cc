#include <bits/stdc++.h>

using namespace std;

int CCW(long long X1, long long X2, long long X3, long long Y1, long long Y2, long long Y3)
{
    long long Temp=(X2-X1)*(Y3-Y1)-(Y2-Y1)*(X3-X1);
    if(Temp>0) return 1; // CCW
    if(Temp<0) return -1; // CW
    return 0; //Collinear
}
bool IsOnLine(long long X1, long long X2, long long X3, long long Y1, long long Y2, long long Y3)
{
    return (X3>=min(X1,X2)&&X3<=max(X1,X2)
           && Y3>=min(Y1,Y2)&&Y3<=max(Y1,Y2));
}
int main()
{
    vector<long long> X(4,0), Y(4,0);
    cin>>X[0]>>Y[0]>>X[1]>>Y[1]>>X[2]>>Y[2]>>X[3]>>Y[3];
    
    int CP012=CCW(X[0],X[1],X[2],Y[0],Y[1],Y[2]);
    int CP013=CCW(X[0],X[1],X[3],Y[0],Y[1],Y[3]);
    int CP230=CCW(X[2],X[3],X[0],Y[2],Y[3],Y[0]);
    int CP231=CCW(X[2],X[3],X[1],Y[2],Y[3],Y[1]);

    int Res=0;
    if(CP012*CP013<0&&CP230*CP231<0)                         Res=1;
    else if(!CP012&&IsOnLine(X[0],X[1],X[2],Y[0],Y[1],Y[2])) Res=1;
    else if(!CP013&&IsOnLine(X[0],X[1],X[3],Y[0],Y[1],Y[3])) Res=1;
    else if(!CP230&&IsOnLine(X[2],X[3],X[0],Y[2],Y[3],Y[0])) Res=1;
    else if(!CP231&&IsOnLine(X[2],X[3],X[1],Y[2],Y[3],Y[1])) Res=1;
    else                                                     Res=0;
    cout<<Res;
}