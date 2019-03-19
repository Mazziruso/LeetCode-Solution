#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

class Solution {
public:
    vector<int> res;
    void DFS(int n) {
        if(n==1) {
            res[0] = 0;
            return;
        }
        
        int inc = n/2;
        DFS(inc);
        int r = n-1;
        int l = 0;
        while(l<r) {
            res[r--] = res[l++] + inc;
        }
    }
    vector<int> grayCode(int n) {
        n = 1<<n;
        res.resize(n);
        DFS(n);
        return res;
    }
};

int main() {

    vector<int> res = Solution().grayCode(3);

    for(int i : res) {
        cout << i << " ";
    }
    cout << endl;

    return 0;
}