#include <iostream>
#include <vector>
#include <algorithm>
#include <set>

using namespace std;

class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
       int n = heights.size();
       if(n==0) {
           return 0;
       }
       int lessFromLeft;
       int lessFromRight;
       int p;
       int maxA=0;
       for(int i=0; i<n; i++) {
           p = i-1;
           while(p>=0 && heights[p]>=heights[i]) {
               p--;
           }
           lessFromLeft = p;
           p = i+1;
           while(p<n && heights[p]>=heights[i]) {
               p++;
           }
           lessFromRight = p;
           maxA = max(maxA, (lessFromRight-lessFromLeft-1)*heights[i]);
       }
       return maxA; 
    }
};

class Solution_1 {
public:
    vector<int> lessFromLeft;
    vector<int> lessFromRight;
    int largestRectangleArea(vector<int>& heights) {
       int n = heights.size();
       int p;
       if(n==0) {
           return 0;
       }
       //preprocess
       lessFromLeft.resize(n);
       lessFromRight.resize(n);
       lessFromLeft[0] = -1;
       lessFromRight[n-1] = n;
       for(int i=1; i<n; i++) {
           p = i-1;
           while(p>=0 && heights[p]>=heights[i]) {
               p = lessFromLeft[p];
           }
           lessFromLeft[i] = p;
       }
       for(int i=n-2; i>=0; i--) {
           p = i+1;
           while(p<n && heights[p]>=heights[i]) {
               p = lessFromRight[p];
           }
           lessFromRight[i] = p;
       }
       int maxA=0;
       for(int i=0; i<n; i++) {
           maxA = max(maxA, (lessFromRight[i]-lessFromLeft[i]-1)*heights[i]);
       }
       return maxA; 
    }
};

int main() {

    vector<int> h({4,3,2,0,3,4,3,4});

    cout << Solution_1().largestRectangleArea(h) << endl;

    return 0;
}