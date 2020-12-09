// 练习哈希
// 超大的二维数组填入n个数
// 0 x y: 交换数组的x行和y行
// 1 x y: 交换数组的x列和y列
// 2 x y: 读取数组当前x行y列的数

#include <iostream>
#include <stdio.h>
#include <algorithm>
using namespace std;

struct point {
    int row;
    int col;
    int value;
    bool operator < (const point &a) const{
       return row < a.row;
     }
} arr[10005];


int x[100005]; //记录当前行号
int y[100005]; //记录当前列号


int n;

void change(int &m1, int &n1) {
    int temp = m1;
    m1 = n1;
    n1 = temp;
}

void find(int m1, int n1) {
    int row = x[m1];
    int col = y[n1];

    int flag = 0;

    for(int i = 0; i < n; ++i) {
        if(arr[i].row == row && arr[i].col == col) {
            printf("%d\n", arr[i].value);
            flag = 1;
            break;
        }
    }
    if(!flag) printf("%d\n",0);
    
}

int main() {
    cin >> n;
    int m;
    for(int i = 0; i < 100005; ++i) {
        x[i] = y[i] = i;
    }
    for(int i = 0; i < n; ++i) {
        scanf("%d%d%d", &arr[i].row, &arr[i].col, &arr[i].value);
        //x_flag[arr[i].row] = 1;
        //y_flag[arr[i].col] = 1;
    }
    //sort(arr,arr+n); 
    cin >> m;
    for(int i = 0; i < m; ++i) {
        int a, b, c;
        scanf("%d%d%d", &a, &b, &c);
        if(a == 0) {
            //change(x_flag[x[b]], x_flag[x[c]]);
            change(x[b], x[c]);
            //cout << x[b] << " " << x[c] << endl;
        } else if(a == 1) {
            //change(y_flag[y[b]], y_flag[y[c]]);
            change(y[b], y[c]);
        } else if(a == 2) {
            find(b, c);
        }
    }
    return 0;
}