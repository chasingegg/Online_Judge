/*
PROG: nuggets
LANG: C++
*/

//2017.7.2
//关键要把输入的包装盒进行排序 用last表示现在不能表示的最大数
//如果last+1, ...last+a[0]都可以表示的话说明last即为所求

#include<iostream>
#include<fstream>
#include<cstdio>
#include<cstdlib>
#include<algorithm>
using namespace std;

ifstream fin("nuggets.in");
ofstream fout("nuggets.out");

int N;
int a[15];
int num[256];

int com(const void *a, const void *b)
{
    return *(int *)a - *(int *)b;
}
void show()
{
    for(int i = 0; i < 16; ++i) {
        for(int j = 0; j < 16; ++j)
            cout << num[i*16 + j] << " ";
        cout << endl;
    }
}
int gcd(int a, int b)
{
    if(a < b) {int temp = b; b = a; a = temp;}
    if(b == 0) return a;
    return gcd(b, a % b);
}
int main()
{
    fin >> N;
    for(int i = 0; i < N; ++i)
        fin >> a[i];
    qsort((void *)a, N, sizeof(int), com);
    //show();
    //cout << gcd(125, 75);
    int _gcd = a[0];
    for(int i = 1; i < N; ++i)
        _gcd = gcd(_gcd, a[i]);
    if(_gcd != 1)
    {
        fout << 0 << endl;
        return 0;
    }
    int last = 0;
    num[0] = 1;
    for(int i = 0; i <= 2000000000; ++i)
    {
        if(num[i % 256])
        {
            num[i % 256] = 0;
            if(i - last >= a[0])
            {
                fout << last << endl;
                //show();
                return 0;
            }
            for(int j = 0; j < N; ++j)
                num[(i + a[j]) % 256] = 1;
        }
        else
            last = i;
    }
    if(last == 2000000000) fout << 0 << endl;
    else
        fout << last << endl;

    return 0;
}
