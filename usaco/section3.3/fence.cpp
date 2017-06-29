/*
PROG: fence
LANG: C++
*/

//2017.6.25
//欧拉道路 dfs 倒序输出 
//无向图中的欧拉道路 如果所有点的度数均为偶数，则任意一点出发均能找到欧拉道路
//如果最多只有两个奇点，那么从任意一个奇点出发到另一个奇点就是一条欧拉道路

#include<iostream>
#include<fstream>
#include<stdlib.h>
using namespace std;

ifstream fin("fence.in");
ofstream fout("fence.out");

int edge[505][505];
int cnt[505];

int len;
int res[2505];
int e;

void dfs(int x)
{
    for(int i = 1; i <= 501; ++i)
    {
        if(edge[x][i] > 0)
        {
            --edge[x][i];
            --edge[i][x];
            dfs(i);
        }
    }
    ++len;
    res[len] = x;
}
int main()
{
    //memset(edge, 0, sizeof(edge));
    fin >> e;
    for(int i = 1; i <= e; ++i) 
    {
        int a, b;
        fin >> a >> b;
        edge[a][b]++; edge[b][a]++;
        cnt[a]++; cnt[b]++;

    }
    int i;
    for(i = 1; i <= 500; ++i)
        if(cnt[i] % 2 == 1)
            break;
    if(i == 501)
    {
        int j;
        for(j = 1; j <= 500; ++j)
            if(cnt[j]) break;
        dfs(j);
    }
    else
    {
        dfs(i);
    }
    for(int i = len; i >= 1; --i)
        fout << res[i] << endl;
    return 0;
}