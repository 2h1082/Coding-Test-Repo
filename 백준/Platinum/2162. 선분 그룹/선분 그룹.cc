#include <bits/stdc++.h>

using namespace std;
using Point=pair<int,int>;
using ll=long long;
class UF
{
private:
    vector<int> Parent;
    vector<int> Cnt;
public:
    UF(int N)
    {
        Parent.resize(N);
        iota(Parent.begin(),Parent.end(),0);
        Cnt.assign(N,1);
    }
    int Find(int v)
    {
        if(Parent[v]!=v)
        {
            return Parent[v]=Find(Parent[v]);
        }
        return v;
    }
    void Merge(int v1, int v2)
    {
        int r1=Find(v1);
        int r2=Find(v2);
        if(r1==r2) return;
        
        if(Cnt[r1]<Cnt[r2])
        {
            swap(r1,r2);
        }
        Cnt[r1]+=Cnt[r2];
        Parent[r2]=r1;
    }
    int CountComponent()
    {
        int Count=0;
        for(int i=0;i<Parent.size();++i)
        {
            if(i==Parent[i]) Count++;
        }
        return Count;
    }
    int CountMaxLine()
    {
        return *max_element(Cnt.begin(),Cnt.end());
    }
};
int CCW(Point A, Point B, Point C)
{
    //{bx-ax, by-ay}, {cx-ax, cy,ay}
    ll Cross=1LL*(B.first-A.first)*(C.second-A.second)-1LL*(B.second-A.second)*(C.first-A.first);
    if(Cross>0) return 1;
    if(Cross<0) return -1;
    return 0;
}

bool IsCross(Point A, Point B, Point C, Point D)
{
    int AB1=CCW(A,B,C), AB2=CCW(A,B,D), CD1=CCW(C,D,A), CD2=CCW(C,D,B);
    int Res1=AB1*AB2, Res2=CD1*CD2;
    if(Res1==0&&Res2==0)
    {
        return (max(A.first,B.first)>=min(C.first,D.first))
               && (max(C.first,D.first)>=min(A.first,B.first))
               && (max(A.second,B.second)>=min(C.second,D.second))
               && (max(C.second,D.second)>=min(A.second,B.second));
    }
    return Res1<=0&&Res2<=0;
}
int main()
{
    int N=0;
    cin>>N;
    vector<pair<Point,Point>> Ps(N);
    for(auto& [p1, p2] : Ps)
    {
        cin>>p1.first>>p1.second>>p2.first>>p2.second;
    }
    UF Set(N);
    for(int i=0;i<N-1;++i)
    {
        for(int j=i+1;j<N;++j)
        {
            if(IsCross(Ps[i].first,Ps[i].second,Ps[j].first,Ps[j].second))
            {
                Set.Merge(i,j);
            }
        }
    }
    cout<<Set.CountComponent()<<"\n"<<Set.CountMaxLine();
}