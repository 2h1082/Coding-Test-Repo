#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int N=0;
vector<vector<int>> Max;
vector<vector<int>> Min;
int main()
{
    cin>>N;
    Max.assign(2,vector<int>(3,0));
    Min.assign(2,vector<int>(3,0));
    int A, B, C;
    cin>>A>>B>>C;
    Max[0][0]=Min[0][0]=Max[1][0]=Min[1][0]=A;
    Max[0][1]=Min[0][1]=Max[1][1]=Min[1][1]=B;
    Max[0][2]=Min[0][2]=Max[1][2]=Min[1][2]=C;
    for(int i=1;i<N;++i)
    {
        cin>>A>>B>>C;
        Max[1][0]=A+max(Max[0][0],Max[0][1]);
        Max[1][1]=B+max({Max[0][0],Max[0][1],Max[0][2]});
        Max[1][2]=C+max(Max[0][1],Max[0][2]);
        Max[0][0]=Max[1][0];
        Max[0][1]=Max[1][1];
        Max[0][2]=Max[1][2];
        
        Min[1][0]=A+min(Min[0][0],Min[0][1]);
        Min[1][1]=B+min({Min[0][0],Min[0][1],Min[0][2]});
        Min[1][2]=C+min(Min[0][1],Min[0][2]);
        Min[0][0]=Min[1][0];
        Min[0][1]=Min[1][1];
        Min[0][2]=Min[1][2];
    }
    
    cout<<*max_element(Max[1].begin(),Max[1].end())<<" "<<*min_element(Min[1].begin(),Min[1].end());
}
