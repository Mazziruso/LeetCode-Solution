#include <iostream>
#include <cmath>
#include <vector>
#include <algorithm>

using namespace std;

struct node {
    int d;
    int pos;
    node() : d(0), pos(0) {};
    node(int d1, int pos1) : d(d1), pos(pos1) {};
};

class Solution {
public:
    vector<node> nodes;

    int partition(int s, int e) {
        node x = nodes[e];
        int j=s-1;
        for(int i=s; i<e; i++) {
            if(nodes[i].d <= x.d) {
                j++;
                swap(nodes[i], nodes[j]);
            }
        }
        j++;
        nodes[e] = nodes[j];
        nodes[j] = x;
        return j;
    }

    int select(int s, int e, int k) {
        if(s<=e) {
            int index = partition(s, e);
            if(index==k) {
                return index;
            } else if(index > k) {
                return select(s, index-1, k);
            } else {
                return select(index+1, e, k);
            }
        }
        return -1;
    }

    vector<vector<int>> kClosest(vector<vector<int>>& points, int K) {
        int n = points.size();
        vector<vector<int>> res;

        for(int i=0; i<n; i++) {
            nodes.push_back(node(points[i][0]*points[i][0]+points[i][1]*points[i][1],i));
        }
        int index = select(0, n-1, K-1);

        for(int i=0; i<=index; i++) {
            res.push_back(points[nodes[i].pos]);
        }
        return res;
    }
};

int main() {

    vector<vector<int>> points({{6,10}, {3,-3}, {-2,5},{0,2}});

    vector<vector<int>> res = Solution().kClosest(points, 3);

    for(int i=0; i<res.size(); i++) {
        cout << res[i][0] << " " << res[i][1] << endl;
    }

    return 0;
}