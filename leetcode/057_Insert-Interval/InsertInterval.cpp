#include <iostream>
#include <vector>
using namespace std;

struct Interval {
    int start;
    int end;
    Interval() : start(0), end(0) {}
    Interval(int s, int e) : start(s), end(e) {}
};
 
class Solution {
public:
    int overlap(Interval v1, Interval v2) {
        if (v1.start > v2.end) return 1;
        else if (v1.end < v2.start) return 2;
        return 3;
    }

    Interval merge(Interval v1, Interval v2) {
        Interval res;
        res.start = min(v1.start, v2.start);
        res.end = max(v1.end, v2.end);
        return res;
    }

    vector<Interval> insert(vector<Interval>& intervals, Interval newInterval) {
        int i; 
        vector<int> temp;
        for (i = 0; i < intervals.size(); ++i) {
            int tmp = overlap(intervals[i], newInterval);
            if (tmp == 1) break;
            if (tmp == 3) {
                newInterval = merge(intervals[i], newInterval);
                temp.push_back(i);
            }
        }
        if (!temp.empty()) {
            intervals.erase(intervals.begin() + temp.front(), intervals.begin() + temp.back() + 1);
            intervals.insert(intervals.begin() + temp.front(), newInterval);
        } else {
            intervals.insert(intervals.begin() + i, newInterval);
        }
        return intervals;
    }
};