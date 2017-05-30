/*
PROG: inflate
LANG: C++
*/

//2017.5.25
//完全背包问题 一个背包的总容量为V,现在有N个物品，第i个物品体积为weight[i]，价值为value[i]，每个物体都有
//无穷多件 如何使得背包的物品价值最大
//f[j] = max(f[j], f[j - weight[i]] + value[i])  
//这里的状态转移方程 解决当前问题，向i种物品的背包添加第i种物品

#include<iostream>
#include<fstream>
using namespace std;

ifstream fin("inflate.in");
ofstream fout("inflate.out");

int weight[100000];
int value[100000];
int f[100000];
int max(int x, int y)
{
    return x>y?x:y;
}
int main()
{
    int V, N; fin >> V >> N;
    for(int i = 0; i < N; ++i)
    {
        fin >> value[i] >> weight[i];
    }
    for(int i = 0 ; i < N; ++i)
    {
        for(int j = weight[i]; j <= V; ++j)
            f[j] = max(f[j], f[j- weight[i]] + value[i]);
    }
    fout << f[V] << endl;
    return 0;
}