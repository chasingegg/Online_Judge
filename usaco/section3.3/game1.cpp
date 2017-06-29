/*
PROG: game1
LANG: C++
*/

//2017.6.29
//这是一道博弈问题，感觉很酷，感觉这种问题是那种典型的用程序解决比数学方法要好的感觉
//dp[i][j]表示i到j之间先手可取的最高分 sum[i][j]是i到j之间的数之和
//状态转移方程 dp[i][j] = sum[i][j] - min(dp[i+1][j], dp[i][j-1])

#include<iostream>
#include<fstream>
#include<cstdio>
#include<cstdlib>
#include<algorithm>
using namespace std;

ifstream fin("game1.in");
ofstream fout("game1.out");

int N;
int a[105];
int sum[105][105];
int dp[105][105];

int main()
{
    fin >> N;
    for(int i = 0; i < N; ++i) fin >> a[i];
    for(int i = 0; i < N; ++i) sum[i][i] = a[i];
    for(int i = 0; i < N; ++i)
        for(int j = i + 1; j < N; ++j)
            sum[i][j] = sum[i][j-1] + a[j];
    
    for(int i = 0; i < N; ++i) dp[i][i] = a[i];

    //dp数组的产生有一定规律的 从两个数开始 直到 全部的数 
    for(int i = 1; i < N; ++i)
        for(int j = 0; j < N - i; ++j)
            dp[j][j+i] = sum[j][j+i] - min(dp[j+1][j+i], dp[j][j+i-1]);
    
    //这样的生成不是局部最优上去的
    //for(int i = 0; i < N; ++i)
      //  for(int j = i + 1; j < N; ++j)
        //    dp[i][j] = sum[i][j] - min(dp[i+1][j], dp[i][j-1]);
    fout << dp[0][N-1] << " " << sum[0][N-1] - dp[0][N-1] << endl;
  
    return 0;
}