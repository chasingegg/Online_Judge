/*
PROG: kimbits
LANG: C++
*/

//2017.6.17
//这题就是个巨坑 暴力做不行 优化一下就是当末尾数是1的时候加1不会对总的1的个数有增加可以减少判断
//还是不行 再次优化就是当N=L时，只需要从小到大开始排就行不用考虑1的个数 最后一个点依旧爆炸
//只好放弃暴力做法了
//a[m][n]表示m位数 n个1
//a[m][n] = a[m - 1][n] + a[m - 1][n - 1]
//还有一个很酷的十进制转成二进制数输出的方式 递归的方式

#include<iostream>
#include<fstream>
using namespace std;

ifstream fin("kimbits.in");
ofstream fout("kimbits.out");

long long a[32][32];
long long N, L, I;

void print_bit(long long res, int bit)
{
    if(bit == 0) return;
    print_bit(res / 2, bit - 1);
    fout << res % 2;
}

int main()
{
    fin >> N >> L >> I;
    for(int i = 0; i <= N; ++i)
        a[i][0] = a[0][i] = 1;
    for(int i = 1; i <= N; ++i)
    {
        for(int j = 1; j < i; ++j)
        {
            a[i][j] = a[i - 1][j] + a[i - 1][j - 1];

        }
        a[i][i] = a[i - 1][i - 1] * 2;
    }
    for(int i = 1; i <= N; ++i)
    {
        for(int j = i + 1; j <= N; ++j)
        {
            a[i][j] = a[i][i];
        }
    }
    long long res = 0;
    for(int i = N - 1; i >= 0; --i)
    {
        res <<= 1;
        if(I > a[i][L])
        {
            I -= a[i][L];
            res += 1;
            --L;
        }
    }
    print_bit(res, N);
    fout << endl;
    return 0;
}
//下面是本来暴力的方法卡在最后第十二个点
/*
int a[32];

int counter = 0; 
int num = 0;
int N;
int L;
int flag = 0;

void plus_one()
{  
    a[0] = (a[0] + 1);
    if(flag == 1) {
        counter = 0;
    for(int i = 0; i < N; ++i)
    {
        a[i + 1] += a[i] / 2;
        a[i] = a[i] % 2;
        if(a[i] == 1)
        {
            ++counter;
        }
    }
    }
    else ++counter;
    flag = 1- flag;
}
int main()
{
    long long I;
    fin >> N >> L >> I;
    int n = 1; 
    int i = 0;
    if(N == L)
    {
        I = I - 1;
        while(1)
        {
            if(I == 0) break;
            a[i++] = I % 2;
            cout << I % 2 << endl;
            I = I / 2;
        }
    }
    else {
    while(1) {
        if(n == I) break;
        plus_one();
        if(counter <= L) ++n;
    }
    }
    for(int i = N - 1; i >= 0; --i)
    {
       fout << a[i];
    }
    fout << endl;
    return 0;
}
*/

