/*
PROG: fence9
LANG: C++
*/

//2017.6.30
//这道题好像完全变了。。看着翻译跟网上的题并没有对上。。
//奇技淫巧 皮克定理 感觉这种题目不太会出现在面试中

#include<iostream>
#include<fstream>
#include<algorithm>
#include<cstdio>
#include<cstdlib>
using namespace std;

ifstream fin("fence9.in");
ofstream fout("fence9.out");

int n, m, p;

int gcd(int x, int y)
{
    if(x < y)
    {
        int tmp = y;
        y = x;
        x = tmp;
    }
    if(y == 0) return x;
    return gcd(y, x % y);
}
int main()
{
    fin >> n >> m >> p;
    int edgenode = gcd(n, m) + gcd(abs(n-p), m) + p;
    int s = p * m / 2;
    fout << s + 1 - edgenode/2 << endl;
    return 0;
}