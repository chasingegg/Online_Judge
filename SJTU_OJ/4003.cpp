// 练习nothing。。没太多意思的一道题

#include <iostream>
#include <stdio.h>
#include <algorithm>
using namespace std;

int n, k;
int tmp[32];

int cal() {
    int x = n;
    int counter = 0;
    for(int i = 0; i < 32; ++i) {
        tmp[31-i] = (x >> i) & 1;
        counter += tmp[31-i];
    }
    return counter;
}

int main() {
    cin >> n >> k;
    if (k >= n) {
        cout << (k - n) << endl;
        return 0;
    }
    int counter = cal();
    if (counter <= k) {
        cout << 0 << endl;
        return 0;
    }
    int res = 0;
    int i;
    for(i = 0; i < 32; ++i) {
        if(tmp[i]) {
            --k;
            res += 1;
        }
        if(!k) {
            res += 1;
            break;
        }
        res <<= 1;
    }
    res <<= (31-i);
    cout << res - n << endl;
    return 0;
}