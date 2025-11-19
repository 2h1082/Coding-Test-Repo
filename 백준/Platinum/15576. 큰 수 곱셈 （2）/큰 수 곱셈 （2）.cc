#include <bits/stdc++.h>
using namespace std;
using cd=complex<double>;
using ll=long long;
const double PI=acos(-1);
void FFT(vector<cd>& A, bool bIsInverse)
{
    int N=A.size();
    for(int i=1,j=0;i<N;++i)
    {
        int Bit=N>>1;
        for(;j&Bit;Bit>>=1) j^=Bit;
        j^=Bit;
        if(i<j) swap(A[i],A[j]);
    }
    
    for(int len=2;len<=N;len<<=1)
    {
        double Ang=2*PI/len*(bIsInverse ? -1 : 1);
        cd Wlen(cos(Ang),sin(Ang));
        for(int i=0;i<N;i+=len)
        {
            cd W(1);
            for(int j=0;j<len/2;++j)
            {
                cd u=A[i+j];
                cd v=A[i+j+len/2]*W;
                
                A[i+j]=u+v;
                A[i+j+len/2]=u-v;
                
                W*=Wlen;
            }
        }
    }
    if(bIsInverse)
    {
        for(cd& x : A) x/=N;
    }
}
string Mul(string s1, string s2)
{
    vector<int> A, B;
    for(int i=s1.size()-1;i>=0;--i) A.push_back(s1[i]-'0');
    for(int i=s2.size()-1;i>=0;--i) B.push_back(s2[i]-'0');
    
    int N=1;
    while(N<A.size()+B.size()) N<<=1;    
    
    vector<cd> Fa(A.begin(),A.end()), Fb(B.begin(),B.end());
    Fa.resize(N);
    Fb.resize(N);
    
    FFT(Fa,false);
    FFT(Fb,false);
    for(int i=0;i<N;++i) Fa[i]*=Fb[i];
    FFT(Fa,true);
    
    vector<int> Res(N,0);
    ll Carry=0;
    for(int i=0;i<N;++i)
    {
        ll T=(ll)llround(Fa[i].real())+Carry;
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
    for(int i=Res.size()-1;i>=0;--i) s+=Res[i]+'0';
    return s;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    string a,b;
    cin>>a>>b;
    cout<<Mul(a,b);
}