#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

class Solution {
public:
    int maxArea(vector<int>& height) {
        int l = 0;
        int r = height.size()-1;
        int mArea = (r - l) * min(height[l], height[r]);
        while(l<r) {
            while(l<r && height[l]<height[r]) {
                l++;
                mArea = max(mArea, ((r - l) * min(height[l], height[r])));
            }
            while(l<r && height[l]>=height[r]) {
                r--;
                mArea = max(mArea, ((r - l) * min(height[l], height[r])));
            }
        }
        return mArea;
    }
    int maxAreaBasic(vector<int>& height) {
        int l = 0;
        int r = height.size()-1;
        int mArea = 0;
        while(l < r) {
            mArea = max(mArea, ((r-l) * min(height[l], height[r])));
            if(height[l] < height[r]) {
                l++;
            } else {
                r++;
            }
        }
        return mArea;
    }
};
