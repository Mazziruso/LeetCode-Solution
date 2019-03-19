#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    int k;
    int n;
    vector<int> comb;
    vector<vector<int>> combs;
    void DFS(int num, int cnt) {
        if(cnt==k) {
            combs.push_back(comb);
            return;
        }
        for(int i=num+1; i<=n; i++) {
            comb.push_back(i);
            DFS(i, cnt+1);
            comb.pop_back();
        }
    }
    vector<vector<int>> combine(int n, int k) {
        this->n = n;
        this->k = k;
        DFS(0,0);
        return combs;
    }
};

int main() {

    vector<vector<int>> res = Solution().combine(4,2);

    for(auto comb : res) {
        for(int i : comb) {
            cout << i << " ";
        }
        cout << endl;
    }

    return 0;
}