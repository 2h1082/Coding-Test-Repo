#include <string>
#include <vector>

using namespace std;

int answer=0;
bool find=false;

void DFS(string CurString, string word)
{
    if(find || CurString.size()>5)
    {
        return;
    }
    if(word==CurString)
    {
        find=true;
        return;
    }
    ++answer;
    DFS(CurString+"A",word);
    DFS(CurString+"E",word);
    DFS(CurString+"I",word);
    DFS(CurString+"O",word);
    DFS(CurString+"U",word);
}

int solution(string word) 
{
    DFS("",word);
    
    return answer;
}
