#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int rangeBitwiseAnd(int m, int n) {
        int count = 0;
		//Right shift both the limits until they are equal
		//since numbers are consecutive, we've to find longest common substring from MSB
        while(m != n) {
            m >>= 1;
            n >>= 1;
            count++;
        }
        return m << count;
    }
};