#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
        int n = matrix.size();
        int tmp1;
        int tmp2;
        for(int k=0; k<n/2; k++) {
            for(int i=k; i<n-1-k; i++) {
                tmp1 = matrix[i][n-1-k];
                tmp2 = matrix[n-1-k][n-1-i];
                matrix[i][n-1-k] = matrix[k][i];
                matrix[n-1-k][n-1-i] = tmp1;

                tmp1 = tmp2;
                tmp2 = matrix[n-1-i][k];
                matrix[n-1-i][k] = tmp1;
                matrix[k][i] = tmp2;
            }
        }
    }
};

int main() {

    Solution s;

    vector<vector<int>> matrix({{5,1,9,11},{2,4,8,10},{13,3,6,7},{15,14,12,16}});

    s.rotate(matrix);

    for(int i=0; i<matrix.size(); i++) {
        for(int j=0; j<matrix[i].size(); j++) {
            cout << matrix[i][j] << " ";
        }
        cout << endl;
    }


    return 0;
}