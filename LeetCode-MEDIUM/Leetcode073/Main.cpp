#include <iostream>
#include <algorithm>
#include <unordered_set>
#include <vector>

using namespace std;

class Solution {
public:
    unordered_set<int> rows;
    unordered_set<int> cols;
    void setZeroes(vector<vector<int>>& matrix) {
        int n=matrix.size();
        if(n==0) {
            return;
        }
        int m=matrix[0].size();
        for(int i=0; i<n; i++) {
            for(int j=0; j<m; j++) {
                if(matrix[i][j]==0) {
                    rows.insert(i);
                    cols.insert(j);
                }
            }
        }
        for(int r : rows) {
            fill(matrix[r].begin(), matrix[r].end(), 0);
        }
        for(int c : cols) {
            for(int i=0; i<n; i++) {
                matrix[i][c] = 0;
            }
        }
    }
};