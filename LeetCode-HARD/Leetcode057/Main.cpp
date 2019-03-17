#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

struct Interval {
    int start;
    int end;
    Interval() : start(0), end(0) {}
    Interval(int s, int e) : start(s), end(e) {}
};

class Solution {
public:
    vector<Interval> intervals;

    int binarySearch(int l, int r, int k) {
        int mid;
        while(l<r) {
            mid = l+(r-l)/2;
            if(intervals[mid].start<k) {
                l = mid+1;
            } else {
                r = mid;
            }
        }
        if(intervals[l].start<k) {
            return l+1;
        }
        return l;
    }

    vector<Interval> insert(vector<Interval>& intervals, Interval newInterval) {
        int n = intervals.size();
        vector<Interval> res;
        if(n==0) {
            res.push_back(newInterval);
            return res;
        }

        this->intervals = intervals;
        int index;
        Interval mergeInt;
        int s,e;
        //start
        index = binarySearch(0, n-1, newInterval.start);

        
        //start
        if(index==n) {
            s = (newInterval.start<=intervals[index-1].end) ? index-1 : index;
            mergeInt.start = (newInterval.start<=intervals[index-1].end) ? intervals[index-1].start : newInterval.start;
        } else if(intervals[index].start != newInterval.start) {
            if(index>0 && intervals[index-1].end>=newInterval.start){
                s = index-1;
                mergeInt.start = intervals[index-1].start;
            } else {
                s = index;
                mergeInt.start = newInterval.start;
            }
        } else {
            s = index;
            mergeInt.start = intervals[index].start;
        }
        //end
        index = binarySearch(0, n-1, newInterval.end);
        if(index==n) {
            e = index;
            mergeInt.end = max(newInterval.end, intervals[index-1].end);
        } else if(intervals[index].start != newInterval.end) {
            if(index>0 && intervals[index-1].end>=newInterval.end){
                e = index;
                mergeInt.end = intervals[index-1].end;
            }else {
                e = index;
                mergeInt.end = newInterval.end;
            }
        } else {
            e = index+1;
            mergeInt.end = intervals[index].end;
        }

        index = 0;
        while(index<s) {
            res.push_back(intervals[index]);
            index++;
        }
        res.push_back(mergeInt);
        index=e;
        while(index<n) {
            res.push_back(intervals[index]);
            index++;
        }
        return res;
    }
};

int main() {

    vector<Interval> ints({Interval(1,5)});

    vector<Interval> res = Solution().insert(ints, Interval(2,3));

    for(auto i : res) {
        cout << i.start << " " << i.end << endl;
    }

    return 0;
}