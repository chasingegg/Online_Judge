/*
PROG: ditch
LANG: C++
*/

//2017.7.3
//最大网络流问题
//Edmonds-Karp 算法

#include<iostream>
#include<fstream>
#include<algorithm>
#include<queue>
#include<cstdio>
#include<cstdlib>
#include<cstring>
using namespace std;

ifstream fin("ditch.in");
ofstream fout("ditch.out");

#define oo 2147400000

int cap[201][201]; //capacity
int flow[201]; //
int pre[201];
int N, M;

int bfs(int src, int des)
{
    queue<int> Q;
    for(int i = 1; i <= M; ++i)
        pre[i] = -1;
    flow[src] = oo;
    pre[src] = 0;
    Q.push(src);
    while(!Q.empty())
    {
        int ind = Q.front(); Q.pop();
        if(ind == des) break; //找到最短路
        for(int i = 1; i <= M; ++i)
        {
            if(pre[i] == -1 && cap[ind][i] > 0)
            {
                pre[i] = ind;
                flow[i] = min(cap[ind][i], flow[ind]);
                Q.push(i);
            }
        }
    }
    if(pre[des] == -1) return -1;
    return flow[des];
}

int main()
{
    fin >> N >> M;
    for(int i = 1; i <= N; ++i)
    {
        int start, end, c; fin >> start >> end >> c;
        if(start == end) continue;
        cap[start][end] += c;
    }
    int sum = 0, increas = 0;
    while((increas = bfs(1, M)) != -1)
    {
        int k = M;
        while(k != 1)
        {
            int last = pre[k];
            cap[last][k] -= increas;
            cap[k][last] += increas;
            k = last;
        }
        sum += increas;
    }
    fout << sum << endl;
    return 0;
}