#include <iostream>
#include <vector>
#include <numeric>

using namespace std;
int main()
{
	int N=0,K=0;
	cin>>N>>K;
    
	vector<int> C(N,0);
	iota(C.begin(),C.end(),1);
	cout<<'<';
	int Cur=0;
	for(int i=0;i<N;++i)
	{
		int Size=C.size();
		int Idx=(Cur+K-1)%Size;
		cout<<C[Idx];
		if(i!=N-1) cout<<", ";
        
		C.erase(C.begin()+Idx);
        
		if(Idx==C.size()) Cur=0;
		else              Cur=Idx;
	} 
	cout<<'>';
}