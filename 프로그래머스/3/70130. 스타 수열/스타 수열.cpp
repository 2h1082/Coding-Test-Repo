#include <vector>
#include <unordered_map>
#include <algorithm>
using namespace std;

int solution(vector<int> a) {
    int n = a.size();
    if (n < 2) return 0;

    unordered_map<int, int> freq;
    freq.reserve(n);
    for (int v : a) {
        freq[v]++;
    }

    vector<pair<int,int>> items;
    items.reserve(freq.size());
    for (auto &kv : freq) 
    {
        items.emplace_back(kv.first, kv.second);
    }
    sort(items.begin(), items.end(), [](auto &L, auto &R) {
        return L.second > R.second; 
    });

    int bestLen = 0;  

    for (auto &p : items) 
    {
        int x = p.first;
        int countX = p.second;

        if (countX * 2 <= bestLen) 
        {
            break;  
        }

        int pairs = 0;
        int i = 0;
        while (i < n - 1) 
        {
            if ((a[i] == x || a[i+1] == x) && (a[i] != a[i+1])) 
            {
                pairs++;
                i += 2;  
            } 
            else 
            {
                i += 1;  
            }
        }

        int lengthWithX = pairs * 2; 
        bestLen = max(bestLen, lengthWithX);
    }

    return bestLen;
}
