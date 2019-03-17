#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

class Solution {
public:
    int num;
    vector<vector<int>> res;

    void recursive(int rowS, int rowE, int colS, int colE) {
        if(rowS>rowE || colS>colE) {
            return;
        }
        for(int i=colS; i<=colE; i++) {
            res[rowS][i] = num++;
        }
        for(int i=rowS+1; i<=rowE; i++) {
            res[i][colE] = num++;
        }
        if(rowS<rowE && colS<colE) {
            for(int i=colE-1; i>=colS; i--) {
                res[rowE][i] = num++;
            }
            for(int i=rowE-1; i>=rowS+1; i--) {
                res[i][colS] = num++;
            }
            recursive(rowS+1, rowE-1, colS+1, colE-1);
        }
    }

    vector<vector<int>> generateMatrix(int n) {

        //initialize
        this->num = 1;
        res.resize(n, vector<int>(n, 0));

        recursive(0, n-1, 0, n-1);

        return res;
    }
};

int main() {

    int n = 0;

    vector<vector<int>> res = Solution().generateMatrix(n);

    for(int i=0; i<n; i++) {
        for(int j=0; j<n; j++) {
            cout << res[i][j] << " ";
        }
        cout << endl;
    }

    return 0;
}