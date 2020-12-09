#include <iostream>
#include <cstdio>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;


 //Definition for an interval.
struct Interval {
    int start;
    int end;
    Interval() : start(0), end(0) {}
    Interval(int s, int e) : start(s), end(e) {}

    void Show() {
        cout << start << " " << end << endl;
    }
};
 
class Solution {
public:
    static bool compare(Interval n1, Interval n2) {
        return n1.start < n2.start;
    }
    vector<Interval> merge(vector<Interval>& intervals) {
        int n = intervals.size();
        if (n <= 1) {
            return intervals;
        }
        sort(intervals.begin(), intervals.end(), compare);
        vector<Interval> res;
        int s = intervals[0].start;
        int e = intervals[0].end;
        for (int i = 1; i < n; ++i) {
            if (e < intervals[i].start) {
                res.push_back(Interval(s, e));
                s = intervals[i].start;
                e = intervals[i].end; 
            } else {
                e = e > intervals[i].end ? e : intervals[i].end;
            }
        }
        res.push_back(Interval(s, e));
        return res;
    }
};