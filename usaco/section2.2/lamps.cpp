/*
PROG: lamps
LANG: C++
*/

//2017.3.27
//枚举法
//这道题很难的感觉 但是最后可以成为一个枚举的问题 原因在于任何按钮按两次相当于没按 所以可以把按的次数降到4以下
//还有一个关键点是无论灯有多少，6个为一个循环
//对于按钮总共可以列举出8种情况 也就是说输出最多八行 这里感觉已经可以纯枚举了。。。
//但是一开始没过，因为有可能还是有同一个按钮按多次的情况需要考虑

#include<iostream>
#include<fstream>
using namespace std;

ifstream fin("lamps.in");
ofstream fout("lamps.out");

int open[7];
int close[7];
int cas[10][10]={{}, {1,1,1,1,1,1}, {0,0,0,0,0,0}, {0,1,0,1,0,1}, {1,0,1,0,1,0}, {0,1,1,0,1,1}, {1,0,0,1,0,0}, {1,1,0,0,0,1}, {0,0,1,1,1,0}};

int N, C;
int flag = 0;
void judge(int num)
{
    int f = 0;
    for(int i = 1; i <= 6; ++i) {
        if(open[i] == 1)
        {
            if(cas[num][i-1] == 0)
                f = 1;
        }
    }
    for(int i = 1; i <= 6; ++i) {
        if(close[i] == 1)
        {
            if(cas[num][i-1] == 1)
                f = 1;
        }
    }
    if(!f)
    {
        for(int i = 0; i < N; ++i) fout << cas[num][i % 6];
        fout << endl;
        flag = 1;
    }
}
int main()
{
    fin >> N >> C;
    while(C > 4) C -= 2;
    int x1, x2;
    while(1) {
        fin >> x1;
        if(x1 == -1) break;
        open[(x1 % 6) > 0 ? (x1 % 6) : (x1 % 6 + 6)] = 1; 
    }
    while(1) {
        fin >> x2;
        if(x2 == -1) break;
        close[(x2 % 6) > 0 ? (x2 % 6) : (x2 % 6 + 6)] = 1;
    }
    if(C == 0) {
        judge(1);
    }
    if(C == 1) {
        judge(2); judge(3); judge(5); judge(4);
    }
    if(C == 2) {
        judge(2); judge(8); judge(3); judge(6); judge(4); judge(7), judge(1);
    }
    if(C >= 3) {
        judge(2); judge(8); judge(3); judge(5); judge(6); judge(4); judge(7), judge(1);
    }
    if(flag == 0) fout << "IMPOSSIBLE" << endl;
    return 0;
}