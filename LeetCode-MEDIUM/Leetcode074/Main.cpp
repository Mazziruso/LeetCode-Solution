#include <iostream>
#include <algorithm>
#include <vector>
#include <cmath>

using namespace std;

class Solution {
public:
    int rowSearch(vector<vector<int>> &mat, int s, int e, int k) {
        int l = s;
        int r = e;
        int mid;
        while(l<r) {
            mid = l+(r-l)/2;
            if(mat[mid][0]<k) {
                l = mid+1;
            } else {
                r = mid;
            }
        }
        return l;
    }
    int colSearch(vector<vector<int>> &mat, int s, int e, int row, int k) {
        int l=s;
        int r=e;
        int mid;
        while(l<r) {
            mid = l+(r-l)/2;
            if(mat[row][mid]<k) {
                l = mid+1;
            } else {
                r = mid;
            }
        }
        return l;
    }
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int n = matrix.size();
        if(n==0) {
            return false;
        }
        int m = matrix[0].size();
        if(m==0) {
            return false;
        }
        
        int row = rowSearch(matrix, 0, n-1, target);
        if(matrix[row][0]==target) {
            return true;
        } else if(matrix[row][0]>target) {
            row--;
        }
        if(row<0) {
            return false;
        }

        int col = colSearch(matrix, 0, m-1, row, target);
        return matrix[row][col]==target;
    }
};