#include <string>
#include <vector>

using namespace std;

vector<int> solution(int n, long long left, long long right) {
    vector<int> arr(right-left+1);
    
    for(long long i=left;i<=right;++i)
    {
        int row=i/n;
        int column=i%n;
        arr[i-left]=max(row,column)+1;
    }
    return arr;
}