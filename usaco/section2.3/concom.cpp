/*
PROG: concom
LANG: C++
*/

//2017.5.3
//dfs 真是写不太好 还是看了解答
//f[][]是dfs标记数组 同时也是标记是否是控股的变量 a[i][j]记录i占有j的股份
//如果有a[i][j]>50的情况 进行关于i的dfs  
#include<iostream>
#include<fstream>
using namespace std;

ifstream fin("concom.in");
ofstream fout("concom.out");

int a[105][105];
int f[105][105];
int num = 0;

int max(int a, int b)
{
    return (a > b) ? a:b;
}
void dfs(int i, int j)
{   
    if(f[i][j]) return;
    //f[i][j] += a[i][j];
    f[i][j] = 1;
    for(int m = 1; m <= num; ++m)
    {
        if(i != m)
        {   
            a[i][m] += a[j][m];
            if(a[i][m] > 50 && !f[i][m])
                dfs(i, m);
        }   
    }
    //}
}
int main()
{
    int i, j, p, N; fin >> N;
    for(int m = 0; m < N; ++m)
    {
        fin >> i >> j >> p;
        a[i][j] = p;
        num = max(num, max(i, j));
    }
    for(int m = 1; m <= num; ++m)
    {
        for(int n = 1; n <= num; ++n)
        {
            if(m != n && a[m][n] > 50)
                dfs(m, n);
        }
    }
    //for(int m = 1; m <= num; ++m)
    //    for(int n = 1; n <= num; ++n)
    //        cout << m << " " << n << " " << f[m][n] << endl;
    for(int m = 1; m <= num; ++m)
    {
        for(int n = 1; n <= num; ++n)
        {
            if(f[m][n])
                fout << m <<" " <<  n << endl;
        }
    }
    return 0;
}