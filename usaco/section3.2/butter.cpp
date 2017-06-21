/*
PROG: butter
LANG: C++
*/

//2017.6.20
//从定点出发 求出最小距离之和
//dijkstra算法+最小堆优化 就当是复习一波dijkstra好了
//是时候学习一波STL了

#include<iostream>
#include<fstream>
#include<queue>
#include<vector>
#include<algorithm>
using namespace std;

ifstream fin("butter.in");
ofstream fout("butter.out");

#define NMAX 505
#define MAX 2147400000
int N, P, C; //奶牛数  牧场数  边的个数
int cow_pos[NMAX];

struct edge
{
    int end;
    int weight;
    int dist;
    bool flag;
    edge *next;
    edge() {}
    edge(int e, int w, edge *n) {end = e; weight = w; next = n;}
};
edge e[500000];

struct res
{
    int index, dist;
    res(int i, int d) {index = i, dist = d;}
};
struct cmp
{
    bool operator()(const res &lhs, const res &rhs)
    {
        return lhs.dist > rhs.dist;      
    }
};

int main()
{
    fin >> N >> P >> C;
    for(int i = 1; i <= N; ++i) fin >> cow_pos[i];
    for(int i = 1; i <= C; ++i)
    {
        int a1, a2, d; fin >> a1 >> a2 >> d;
        e[a1].next = new edge(a2, d, e[a1].next);
        e[a2].next = new edge(a1, d, e[a2].next); 
    }
    int ans = MAX;
    for(int i = 1; i <= P; ++i)
    {
        for(int j = 1; j <= P; ++j)
        {
            e[j].dist = MAX;
            e[j].flag = false;
        }
        e[i].dist = 0;
        priority_queue<res, vector<res>, cmp> Q;
        Q.push(res(i, 0));
        while(!Q.empty())
        {
            res r = Q.top(); Q.pop();
            int I = r.index; 
            int D = r.dist;

            if(!e[I].flag)
            {
                e[I].flag = true;
                for (edge *start = e[I].next; start ;start = start -> next)
                {
                    int n = start -> end, c = start -> weight;
                    if (e[n].dist > e[I].dist + c)
                    {
                        e[n].dist = e[I].dist + c;
                        Q.push(res(n, e[n].dist));
                    }
                }
            }
        }

        int tmp = 0;
        for(int i = 1; i <= N; ++i)
        {
            tmp += e[cow_pos[i]].dist;
        }
        if(tmp < ans) ans = tmp;
    }
    
    fout << ans << endl;
    return 0;
}