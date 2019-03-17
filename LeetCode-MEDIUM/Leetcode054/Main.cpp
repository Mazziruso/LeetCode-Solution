#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

class Solution {
public:
    vector<int> res;
    vector<vector<int>> mat;

    void spiralRecursive(int rowS, int rowE, int colS, int colE) {
        if(rowS>rowE || colS>colE) {
            return;
        }
        for(int i=colS; i<=colE; i++) {
            res.push_back(mat[rowS][i]);
        }
        for(int i=rowS+1; i<=rowE; i++) {
            res.push_back(mat[i][colE]);
        }
        if(colS!=colE && rowS!=rowE) {
            for(int i=colE-1; i>=colS; i--) {
                res.push_back(mat[rowE][i]);
            }
            for(int i=rowE-1; i>rowS; i--) {
                res.push_back(mat[i][colS]);
            }
            spiralRecursive(rowS+1, rowE-1, colS+1, colE-1);
        }
    }

    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        this->mat = matrix;
        int n = matrix.size();
        int m = (n>0) ? matrix[0].size() : 0;
        spiralRecursive(0, n-1, 0, m-1);
        return res;
    }
};

int main() {
    vector<vector<int>> matrix({{1,2,3},{4,5,6},{7,8,9},{10,11,12}});
    Solution s;
    vector<int> res = s.spiralOrder(matrix);
    for(int i=0; i<res.size(); i++) {
        cout << res[i] << " ";
    }
    cout << endl;
    return 0;
}