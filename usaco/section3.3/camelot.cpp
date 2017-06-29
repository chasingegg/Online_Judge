/*
PROG: camelot
LANG: C++
*/

//2017.6.28
//这道题仿佛回想起了数据结构机考的第二题 想想当时的雪崩场景 现在似乎也没好多少
//对于bfs dfs这种真心是弃疗
//骑士类似于 马 的走法
//其实本质上是一种枚举的方法，先排出骑士从任意一点到别的点的步数
//

#include<iostream>
#include<fstream>
#include<algorithm>
#include<queue>
#include<utility>
#include<cstdlib>
using namespace std;

ifstream fin("camelot.in");
ofstream fout("camelot.out");

#define INF 214740000
#define ii pair<int, int>
#define iii pair<ii, int>

int R, C; //行 列数
int kx, ky;  //king的位置
int x, y;
int K;
int dist[27][31][27][31];
int dc[8] = {1, 2, 2, 1, -1, -2, -2, -1}, dr[8] = {-2, -1, 1, 2, 2, 1, -1, -2};//跳的方向
bool visit[27][31];
int ksc, kec, ksr, ker;
char ch;
int cur, wk;
int d;

struct Knight 
{
    int x, y;
};
Knight knt[1000];

void bfs(int c, int r) //从(c, r)点出发走到棋盘上的其他点
{
    for(int i = 1; i <= 26; ++i)
        for(int j = 1; j <= 30; ++j)
            visit[i][j] = 0;
    int x, y;
    queue<iii> Q;
    Q.push(iii(ii(c, r), 0));
    while(!Q.empty())
    {
        iii st = Q.front(); Q.pop();
        x = st.first.first; y = st.first.second;
        if(visit[x][y]) continue;
        visit[x][y] = true;
        d = st.second;
        dist[c][r][x][y] = d; //关键是得到dist
        for(int i = 0; i < 8; ++i)
        {
            int newx = x + dc[i];
            int newy = y + dr[i];
            if(newx > 0 && newx <= C && newy > 0 && newy <= R)
                Q.push(iii(ii(newx, newy), d + 1));
        }
    }
}
int main()
{   
    int ans = 0;
    fin >> R >> C; 
    fin >> ch >> ky; kx = ch - 'A' + 1;
    while(fin >> ch >> y)
    {
        ++K;
        knt[K].x = ch - 'A' + 1;
        knt[K].y = y;
    }   
    for(int ic = 1; ic <= C; ++ic)
        for(int ir = 1; ir <= R; ++ir)
            for(int jc = 1; jc <= C; ++jc)
                for(int jr = 1; jr <= R; ++jr)
                    dist[ic][ir][jc][jr] = INF;
    
    for(int i = 1; i <= C; ++i)
        for(int j = 1; j <= R; ++j)
            bfs(i, j);

    //下面主要考虑国王
    ksc = max(1, kx - 2);
    kec = min(C, kx + 2);
    ksr = max(1, ky - 2);
    ker = min(R, ky + 2);

    for(int c = 1; c <= C; ++c)
        for(int r = 1; r <= R; ++r)
        {
            cur = wk = 0;
            for(int k = 1; k <= K; ++k)
                cur += dist[knt[k].x][knt[k].y][c][r];//骑士步数之和
            for(int kc = ksc; kc <= kec; ++kc)
                for(int kr = ksr; kr <= ker; ++kr)
                    for(int kk = 1; kk <= K; ++kk)
                    {
                        wk = dist[knt[kk].x][knt[kk].y][kc][kr] + dist[kc][kr][c][r];//前半部分到达国王的领地，后半部分国王骑士一起走
                        wk += max(abs(kx - kc), abs(ky - kr));//国王步数
                        wk = wk + cur - dist[knt[kk].x][knt[kk].y][c][r];
                        if(ans == 0 || ans > wk)
                            ans = wk;
                    }
        }
    fout << ans << endl;
    return 0;
}