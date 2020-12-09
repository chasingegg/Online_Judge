#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

class Solution {
public:
    int hIndex(vector<int> &citations) {
        sort(citations.begin(), citations.end());
        int n = citations.size();
        for (int i = n-1; i >= 0; --i) {
            if (n-i <= citations[i]) {  // n-i个大于n-i
                if (i == 0) return n;
                if (n-i >= citations[i-1]) return n-i; //
            }
        }
        return 0;
    }
};