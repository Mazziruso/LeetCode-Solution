#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

struct Interval {
    int start;
    int end;
    Interval() : start(0), end(0) {}
    Interval(int s, int e) : start(s), end(e) {}
};

bool cmp1(const Interval &v1, const Interval &v2) {
        return v1.start<v2.start;
}

class Solution {
public:

    vector<Interval> merge(vector<Interval>& intervals) {
        vector<Interval> res;
        if(intervals.size() == 0) {
            return res;
        }

        sort(intervals.begin(), intervals.end(), cmp1);
        
        res.push_back(intervals[0]);
        for(int i=1; i<intervals.size(); i++) {
            if(intervals[i].start>res[res.size()-1].end) {
                res.push_back(intervals[i]);
            } else {
                res[res.size()-1].end = max(res[res.size()-1].end, intervals[i].end);
            }
        }
        return res;
    }
};

int main() {

    vector<Interval> intervals({Interval(1,3), Interval(2,6),Interval(5,9), Interval(8,10), Interval(15,18)});

    Solution s;
    vector<Interval> res = s.merge(intervals);

    return 0;
}