#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int monotoneIncreasingDigits(int N) {
        int num[10];
        int i = 0;
        while (N != 0) {
            num[i++] = N % 10;
            N = N / 10;
        }
        int flag = 0;
        for (int index = i - 1; index >= 1; --index) {
            if (flag == 0) {
                if (num[index-1] < num[index]) {
                    int tmp = index+1;
                    while (tmp <= i - 1) {
                        if (num[tmp-1] - 1 < num[tmp]) {
                            tmp++;
                        } else {
                            break;
                        }
                    }
                    num[index-1] = 9;
                    num[tmp-1]--;
                    for (int j = tmp-2; j >= index; --j) {
                        num[j] = 9;
                    }
                    flag = 1;
                }
            } else {
                num[index] = 9;
                if (index == 1) {
                    num[index-1] = 9;
                }
            }
        }
        int res = 0;
        for (int index = i - 1; index >= 0; --index) {
            res = res * 10 + num[index];
        }
        return res;
    }
};
