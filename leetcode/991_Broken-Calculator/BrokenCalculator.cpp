#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int brokenCalc(int X, int Y) {
        if (X >= Y) {
            return X - Y;
        }
        int counter = 0;
        while (X < Y) {
            if (Y % 2) {
                Y++;
                Y /= 2;
                counter += 2;
            } else {
                Y /= 2;
                ++counter;
            }
        }
        return counter + X - Y;
    }
};