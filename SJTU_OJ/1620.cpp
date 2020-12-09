// 练习树状数组 牢记树状数组的优势在于频繁地查询数组内某一个区间的和
// 输入一个长度为n的数组做和异或有关的查询
// 1 x y 表示把第x个元素变成y 
// 0 l r 表示区间[l, r]的答案，答案就是这个区间内任意两个数进行异或运算得到的值
// trick: 开一个32维的树状数组，表示32位数字的某一位上1出现的次数

#include <iostream>
#include <stdio.h>
using namespace std;

int n;
int a[60005] = {0};
int c[32][60005] = {0};

long long lowbit(int x) {
    return x & -x;
}

void change(int index, int p) {   //a[index] change to p
    int index_tmp;
    for(int i = 0; i < 32; ++i) {
        index_tmp = index;
        
        if (!( ((p >> i) & 1) == ((a[index_tmp] >> i) & 1) )) {
            if ( ((p >> i) & 1) ) {
                while(index_tmp <= n) {
                    c[i][index_tmp] += 1;
                    index_tmp += lowbit(index_tmp);
                }
            }
            else {
                while(index_tmp <= n) {
                    c[i][index_tmp] -= 1;
                    index_tmp += lowbit(index_tmp);
                }
            }
        }
    }
    a[index] = p;
}

int getsum(int index, int i ) {
    int index_tmp, ans_tmp;
    long long ans = 0;
    index_tmp = index;
    ans_tmp = 0;
    while(index_tmp > 0) {
        ans_tmp += c[i][index_tmp];
        index_tmp -= lowbit(index_tmp); 
    }
    ans += ans_tmp;
    
    return ans;
}
int main() {
    cin >> n;
    for(int i = 1; i <= n; ++i) {
        int shit;
        scanf("%d", &shit);
        change(i, shit);
    }

    int q; cin >> q;
    int q_1, q_2, q_3;
    for(int i = 0; i < q; ++i) {
        cin >> q_1 >> q_2 >> q_3;
        if(q_1 == 1) {
            change(q_2, q_3);
        }
        if(q_1 == 0) {
            long long  temp = 0;
            for(int j = 0; j < 32; ++j) {
                long long t = getsum(q_3, j) - getsum(q_2-1, j);
                temp += ((t * (q_3 - q_2 + 1 - t)) << j) % 1000000007;
               
            }
            cout << temp % 1000000007 << endl;
        }
    }
    return 0;
}