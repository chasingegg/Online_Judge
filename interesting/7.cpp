/*
两个排好序的序列，找出第k小的元素
*/

// naive的方法就是顺序地查，复杂度是O(N)
// 二分优化(这时候说明其实这是用数组存的)
#include <iostream>
using namespace std;

int a[100];
int b[100];

int K = 20;

int sol1(int k) {
    int p1 = 0; int p2 = 0;
    while (1) {
        --k;
        if (a[p1] <= b[p2]) {
            if (k <= 0) return a[p1];
            p1++;
        } else {
            if (k <= 0) return b[p2];
            p2++;
        }
    }
    return 0;
}

int sol2(int p1, int p2, int k1, int k2, int k) {
    if (k1 == 0) return b[p2+k-1];
    if (k2 == 0) return a[p1+k-1];
    if (a[p1+])
}

int main() {
    for (int i = 0; i < 100; ++i) {
        a[i] = i + 10;
        b[i] = i * 2;
    }
    int res = sol1(K);
    int res2 = sol2(K);
    cout << res << " " << res2 << endl;
    return 0;
}