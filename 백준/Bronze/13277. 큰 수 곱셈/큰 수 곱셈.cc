#include "bits/stdc++.h"
using namespace std;
using cd = complex<double>;
using ll = long long;
const double PI=acos(-1);
void FFT(vector<cd>& a, bool Invert)
{
    int N=a.size();
    for(int i=1,j=0;i<N;++i)
    {
        int Bit=N>>1;
        for(;j&Bit;Bit>>=1) j^=Bit;
        j^=Bit;
        if(i<j) swap(a[i],a[j]);
    }
    for(int len=2;len<=N;len<<=1)
    {
        double Ang=2*PI/len*(Invert?-1:1);
        cd wlen(cos(Ang),sin(Ang));
        for(int i=0;i<N;i+=len)
        {
            cd w(1);
            for(int j=0;j<len/2;++j)
            {
                cd u=a[i+j];
                cd v=a[i+j+len/2]*w;
                a[i+j]=u+v;
                a[i+j+len/2]=u-v;
                w*=wlen;
            }
        }
    }
    if(Invert)
    {
        for (cd& x : a) x/=N;
    }
}
string Mul(string& A, string& B)
{
    vector<int> a, b;
    for(int i=A.size()-1;i>=0;--i) a.push_back(A[i]-'0');
    for(int i=B.size()-1;i>=0;--i) b.push_back(B[i]-'0');
    
    int N=1;
    while(N<a.size()+b.size()) N<<=1;
    
    vector<cd> fa(a.begin(),a.end()), fb(b.begin(),b.end());
    fa.resize(N);
    fb.resize(N);
    
    FFT(fa,false);
    FFT(fb,false);
    for(int i=0;i<N;++i) fa[i]*=fb[i];
    FFT(fa,true);
    
    vector<int> Res(N);
    ll Carry=0;
    for(int i=0;i<N;++i)
    {
        ll T=(ll)llround(fa[i].real())+Carry;
        Res[i]=T%10;
        Carry=T/10;
    }
    while(Carry)
    {
        Res.push_back(Carry%10);
        Carry/=10;
    }
    
    while(Res.size()>1 && Res.back()==0) Res.pop_back();
    
    string s;
    for(int i=Res.size()-1;i>=0;--i) s.push_back(Res[i]+'0');
    return s;
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    string A,B;
    cin>>A>>B;
    
    cout<<Mul(A,B);
}