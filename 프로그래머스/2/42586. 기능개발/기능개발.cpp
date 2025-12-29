#include <vector>
using namespace std;

vector<int> solution(vector<int> Progresses, vector<int> Speeds) 
{
    vector<int> Ans;
    int N=Speeds.size(), Max=0;
    
    for(int i=0;i<N;++i)
    {
        int Cur=(99-Progresses[i])/Speeds[i] + 1;
        if(Ans.empty() || Cur > Max)
        {
            Ans.push_back(1);
            Max=max(Cur,Max);
        }
        else
        {
            Ans.back()++;
        }
    }
    return Ans;
}