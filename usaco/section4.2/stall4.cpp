/*
PROG: stall4
LANG: C++
*/

//2017.7.12
//二分图最大匹配 匈牙利算法
#include<iostream>
#include<fstream>
#include<cstring>
#include<algorithm>

using namespace std;

ifstream fin("stall4.in");
ofstream fout("stall4.out");

int N, M;
int a[205][205];
int f[205];
int match[205];

bool dfs(int x)
{
    for(int i = 1; i <= M; ++i)
    {
        if(a[x][i] && f[i] == false)
        {
            f[i] = true;
            if(match[i] == 0 || dfs(match[i]))
            {
                match[i] = x;
                return true;
            }
        }
    }
    return false;
}
int main()
{
    int ans = 0;
    fin >> N >> M;
    for(int i = 1; i <= N; ++i)
    {
        int num; fin >> num;
        for(int j = 0; j < num; ++j)
        {
            int v; fin >> v;
            a[i][v] = 1;
        }
    }

    for(int i = 1; i <= N; ++i)
    {
        memset(f, 0, sizeof(f));
        if(dfs(i)) ++ans;
    }
    fout << ans << endl;
    return 0;
}