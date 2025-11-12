#include <bits/stdc++.h>
using namespace std;
using ll=long long;

struct Point
{
    int x, y, idx;
};
int CCW(Point& A, Point& B, Point& C)
{
    return (B.x-A.x)*(C.y-A.y)-(B.y-A.y)*(C.x-A.x);    
}

int Dist(Point& A, Point& B)
{
    int dx=B.x-A.x, dy=B.y-A.y;
    return dx*dx+dy*dy;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    
    int c=0;
    cin>>c;
    while(c--)
    {
        int n=0;
        cin>>n;
        vector<Point> A(n);
        for(int i=0;i<n;++i)
        {
            cin>>A[i].x>>A[i].y;
            A[i].idx=i;
        }
        int s=0;
        for(int i=1;i<n;++i)
        {
            if(A[i].x<A[s].x || (A[i].x==A[s].x&&A[i].y<A[s].y)) s=i;
        }
        swap(A[0],A[s]);
        
        sort(A.begin()+1,A.end(), [&](Point& a, Point& b){
            int C=CCW(A[0],a,b);
            if(C) return C>0;
            return Dist(A[0],a)<Dist(A[0],b);
        });
        int Idx=n-1;
        while(Idx>1&&CCW(A[0],A[Idx-1],A[Idx])==0) --Idx;
        reverse(A.begin()+Idx,A.end());
        
        for(int i=0;i<n;++i)
        {
            cout<<A[i].idx<<' ';
        }
        cout<<'\n';
    }
}