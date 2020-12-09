//学习一个树状数组
//应用场景是需要多次计算区间的和
//计算区间的和复杂度从O(N)降为O(logN)
//同时修改某一个值复杂度从O(1)变为O(logN)

#include <iostream>
#include <cstring>
using namespace std;

int n;
int a[100000];  //原数组
int c[100000];  //树状数组 c[index]保存的是a[index], a[index-1]...a[index-lowbit(index)+1]的和

int lowbit(int x) {  //神奇的操作，每次的间隔
    return x & -x;
}

int change(int index, int p) { //对a[x]加p，对树状数组要逐个改变
    while(index <= n) {
        c[index] += p;
        index += lowbit(index);
    }
}

int getsum(int index) { //得到从头到index的原数组的和，把对应的树状数组加起来
    int ans = 0;
    while(index > 0) {
        ans += c[index];
        index -= lowbit(index);
    }
    return ans;
}

int main() 
{
    cin >> n;
    char query[10];
    for(int i = 1; i <= n; ++i) {
        cin >> a[i];
        change(i, a[i]);
    }
    while(1) {
        int x, y;
        cin >> query;
        if(strcmp(query, "query") == 0) {cin >> x >> y; cout << getsum(y) - getsum(x-1) << endl;}
        if(strcmp(query, "inc") == 0) {cin >> x >> y; change(x, y);}
        if(strcmp(query, "dec") == 0) {cin >> x >> y; change(x, -y);}
        if(strcmp(query, "end") == 0) break;
    }
    return 0;
}