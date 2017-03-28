/*
PROG: holstein
LANG: C++
*/

//2017.3.23
//这道题也是蛮暴力的 不过感觉突然 似乎 觉得二进制数是一个挺有意思的东西
//很多写不好循环的东西都可以化成二进制 然后简化运算
//本来按照二进制从小开始筛选后找到就行了，后来发现了问题，有可能后面的需要的种类有可能更少
//然后就写得有些乱了，记下min_count表示当前最少种类个数，ans[][]记录每次答案，第一维是种类个数作为index索引

#include<iostream>
#include<fstream>
using namespace std;

ifstream fin("holstein.in");
ofstream fout("holstein.out");

int V;
int a[35];
int tmp[35];
int G; 
int b[16][35];
int res[16];
int size = 0;
int ans[35][35];

bool judge(int x)
{
    size = 0;
    for(int i = 0; i < G; ++i){
        res[i] = 0;
    }
    for(int i = 0; i < V; ++i)
    {
        tmp[i] = 0;
    }
    for(int i = 0; i < G; ++i)
    {
        if((x & 1) == 1) {
            res[i] = 1;
            ++size;
        for(int j = 0; j < V; ++j) {
            tmp[j] += b[i][j];
        }
        }
        x >>= 1;
    }
    for(int i = 0; i < V; ++i)
        if(tmp[i] < a[i]) return false;
    return true;
}
int main()
{
    int index = 0;
    int min_count = 30;
    int fina = 0;
    fin >> V;
    for(int i = 0; i < V; ++i) fin >> a[i];
    fin >> G;
    for(int i = 0; i < G; ++i) for(int j = 0; j < V; ++j) fin >> b[i][j];
    for(int i = 1; i < (1 << G); ++i)
    {
        if(judge(i)) 
        {
            if(size < min_count) 
            {
            for(int i = 0; i < G; ++i)
            {
                ans[size][i] = res[i];
            }
            min_count = size;
            }
        }
    }
    fout << min_count << " ";
    for(int i = 0; i < G; ++i)
    {
        if(ans[min_count][i])
        {
            if(++fina == min_count)
             fout << i + 1 << endl; 
            else
                fout << i + 1 << " ";
        }
    }
    return 0;
}