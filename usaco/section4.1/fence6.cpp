/*
PROG: fence6
LANG: C++
*/

//2017.7.2
//找无向图中的最小环 
//使用dfs枚举所有情况

#include<iostream>
#include<fstream>
#include<algorithm>
#include<cstdio>
#include<cstdlib>
#include<cstring>
using namespace std;

ifstream fin("fence6.in");
ofstream fout("fence6.out");

#define oo 2147400000

struct edge
{
    int prev[10];
    int post[10];
    int len, n1, n2;
};
edge a[105];
int N;
int f[105];
int start;
int res;

void dfs(int pre, int pos, int cur_len)
{
    if(f[pos] != -1 && pos == start)
    {
        if(res > cur_len)
        {
            res = cur_len;
        }
        return;
    }
    if(f[pos] != -1 && f[pos] < cur_len) return;
    f[pos] = cur_len;
    cur_len += a[pos].len;
    int dir = 0;
    for(int i = 1; i <= a[pos].n1; ++i)
        if(a[pos].prev[i] == pre) 
            dir = 1;
    if(dir) {
        for(int i = 1; i <= a[pos].n2; ++i)
            dfs(pos, a[pos].post[i], cur_len);
    } else {
        for(int i = 1; i <= a[pos].n1; ++i)
            dfs(pos, a[pos].prev[i], cur_len);
    }
}
int main()
{
    fin >> N;
    for(int i = 1; i <= N; ++i)
    {
        int s, l, n1, n2; fin >> s >> l >> n1 >> n2;
        a[s].len = l;
        a[s].n1 = n1;
        a[s].n2 = n2;
        for(int j = 1; j <= n1; ++j)
            fin >> a[s].prev[j];
        for(int j = 1; j <= n2; ++j)
            fin >> a[s].post[j];
        
    }
    res = oo;
    for(int i = 1; i <= N; ++i)
    {
        memset(f, -1, sizeof(f));
        start = i;
        dfs(0, i, 0);
    } 
    fout << res << endl;
    return 0;
}